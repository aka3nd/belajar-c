#include <gtk/gtk.h>
#include <math.h>

/* ===== Warna ===== */
typedef struct { double r, g, b; } Color;

static const Color PUTIH     = {1.00, 1.00, 1.00};
static const Color HITAM     = {0.13, 0.13, 0.13};
static const Color MERAH_TUA = {0.78, 0.36, 0.36};
static const Color ORANYE    = {0.96, 0.35, 0.16};
static const Color KUNING    = {0.96, 0.64, 0.10};
static const Color HIJAU     = {0.24, 0.69, 0.26};
static const Color MERAH     = {0.88, 0.13, 0.13};

/* Jenis ikon yang ada di gambar */
typedef enum {
    IKON_POWER,
    IKON_REBOOT,
    IKON_SOFT,
    IKON_RECOVERY,
    IKON_BOOTLOADER,
    IKON_SAFE
} IkonJenis;

/* Data yang dibawa ke fungsi penggambar */
typedef struct {
    IkonJenis kind;
    Color fg;   /* warna utama (lingkaran atau cincin) */
    Color bg;   /* warna kedua (cincin hitam pada Recovery) */
} IconData;

static void set_color(cairo_t *cr, Color c)
{
    cairo_set_source_rgb(cr, c.r, c.g, c.b);
}

/* Busur dengan mata panah di ujungnya.
 * Sudut dalam radian; 0 = kanan, bertambah searah jarum jam. */
static void draw_arrow_arc(cairo_t *cr, double cx, double cy, double r,
                           double lw, double a0, double a1, gboolean arrow)
{
    cairo_set_line_width(cr, lw);
    cairo_set_line_cap(cr, CAIRO_LINE_CAP_BUTT);
    cairo_new_path(cr);
    cairo_arc(cr, cx, cy, r, a0, a1);
    cairo_stroke(cr);

    if (!arrow)
        return;

    /* Titik ujung busur */
    double tx = cx + r * cos(a1);
    double ty = cy + r * sin(a1);

    double dx = -sin(a1), dy = cos(a1);  /* arah gerak busur */
    double nx =  cos(a1), ny = sin(a1); /* arah keluar dari pusat */
    double s = lw * 1.2;                 /* ukuran mata panah */

    cairo_new_path(cr);
    cairo_move_to(cr, tx + dx * s, ty + dy * s);   /* ujung panah */
    cairo_line_to(cr, tx + nx * s, ty + ny * s);   /* sisi luar */
    cairo_line_to(cr, tx - nx * s, ty - ny * s);   /* sisi dalam */
    cairo_close_path(cr);
    cairo_fill(cr);
}

/* Simbol power: busur terbuka di atas dan garis lurus ke tengah */
static void draw_power(cairo_t *cr, double cx, double cy, double r, double lw)
{
    cairo_set_line_width(cr, lw);
    cairo_set_line_cap(cr, CAIRO_LINE_CAP_ROUND);

    cairo_new_path(cr);
    cairo_arc(cr, cx, cy, r, -G_PI / 2 + 0.7, -G_PI / 2 + 2 * G_PI - 0.7);
    cairo_stroke(cr);

    cairo_move_to(cr, cx, cy - r * 1.15);
    cairo_line_to(cr, cx, cy);
    cairo_stroke(cr);
}

/* Fungsi penggambar utama, dipanggil GTK setiap widget perlu digambar ulang */
static void draw_icon(GtkDrawingArea *area, cairo_t *cr,
                      int w, int h, gpointer data)
{
    IconData *d = data;
    double cx = w / 2.0;
    double cy = h / 2.0;
    double R  = MIN(w, h) / 2.0 - 1.0;

    switch (d->kind) {
    case IKON_POWER:
        set_color(cr, d->fg);
        cairo_arc(cr, cx, cy, R, 0, 2 * G_PI);
        cairo_fill(cr);
        set_color(cr, PUTIH);
        draw_power(cr, cx, cy, R * 0.55, R * 0.12);
        break;

    case IKON_REBOOT:
        set_color(cr, d->fg);
        cairo_arc(cr, cx, cy, R, 0, 2 * G_PI);
        cairo_fill(cr);
        set_color(cr, PUTIH);
        draw_arrow_arc(cr, cx, cy, R * 0.5, R * 0.16, -1.2, 4.0, TRUE);
        break;

    case IKON_SOFT:
        set_color(cr, d->fg);
        cairo_arc(cr, cx, cy, R, 0, 2 * G_PI);
        cairo_fill(cr);
        set_color(cr, PUTIH);
        draw_arrow_arc(cr, cx, cy, R * 0.42, R * 0.16, -1.0, 3.8, TRUE);
        break;

    case IKON_RECOVERY:
        /* Cincin hitam di bawah, panah hijau di atas */
        set_color(cr, d->bg);
        draw_arrow_arc(cr, cx, cy, R * 0.8, R * 0.22, 0.5, 4.0, FALSE);
        set_color(cr, d->fg);
        draw_arrow_arc(cr, cx, cy, R * 0.8, R * 0.22, -2.0, 0.3, TRUE);
        break;

    case IKON_BOOTLOADER:
        /* Dua panah merah berlawanan */
        set_color(cr, d->fg);
        draw_arrow_arc(cr, cx, cy, R * 0.8, R * 0.22, -2.1, 0.9, TRUE);
        draw_arrow_arc(cr, cx, cy, R * 0.8, R * 0.22, 1.1, 4.1, TRUE);
        break;

    case IKON_SAFE:
        set_color(cr, d->fg);
        draw_arrow_arc(cr, cx, cy, R * 0.8, R * 0.22, -2.0, 3.9, TRUE);
        break;
    }
}

/* Membuat area gambar ikon dengan ukuran tertentu */
static GtkWidget *make_icon(IkonJenis kind, Color fg, Color bg, int size)
{
    IconData *d = g_new0(IconData, 1);
    d->kind = kind;
    d->fg = fg;
    d->bg = bg;

    GtkWidget *area = gtk_drawing_area_new();
    gtk_widget_set_size_request(area, size, size);
    /* g_free dipanggil otomatis saat widget dihancurkan */
    gtk_drawing_area_set_draw_func(GTK_DRAWING_AREA(area), draw_icon, d, g_free);
    return area;
}

/* Satu baris menu: ikon di kiri, judul dan keterangan opsional di kanan */
static GtkWidget *make_menu_item(const char *judul, const char *keterangan,
                                 GtkWidget *ikon)
{
    GtkWidget *baris = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 18);
    gtk_widget_set_margin_start(baris, 22);
    gtk_widget_set_margin_end(baris, 22);
    gtk_widget_set_margin_top(baris, 10);
    gtk_widget_set_margin_bottom(baris, 10);
    gtk_box_append(GTK_BOX(baris), ikon);

    GtkWidget *teks = gtk_box_new(GTK_ORIENTATION_VERTICAL, 2);
    gtk_widget_set_hexpand(teks, TRUE);
    gtk_widget_set_valign(teks, GTK_ALIGN_CENTER);

    GtkWidget *label = gtk_label_new(judul);
    gtk_label_set_xalign(GTK_LABEL(label), 0.0);
    gtk_widget_add_css_class(label, "judul-menu");
    gtk_box_append(GTK_BOX(teks), label);

    if (keterangan) {
        GtkWidget *sub = gtk_label_new(keterangan);
        gtk_label_set_xalign(GTK_LABEL(sub), 0.0);
        gtk_label_set_wrap(GTK_LABEL(sub), TRUE);
        gtk_widget_add_css_class(sub, "keterangan");
        gtk_box_append(GTK_BOX(teks), sub);
    }

    gtk_box_append(GTK_BOX(baris), teks);
    return baris;
}

/* Satu kolom di bagian bawah: ikon di atas, label di bawah */
static GtkWidget *make_bottom_item(const char *judul, IkonJenis kind,
                                   Color fg, Color bg)
{
    GtkWidget *kolom = gtk_box_new(GTK_ORIENTATION_VERTICAL, 6);
    gtk_box_append(GTK_BOX(kolom), make_icon(kind, fg, bg, 56));

    GtkWidget *label = gtk_label_new(judul);
    gtk_widget_add_css_class(label, "label-bawah");
    gtk_box_append(GTK_BOX(kolom), label);
    return kolom;
}

/* CSS untuk warna, bayangan, dan ukuran teks */
static void pasang_css(void)
{
    const char *css =
        "window { background: #00bcd4; }"
        ".kartu { background: #efefef; border-radius: 4px;"
        "         padding: 14px 0; box-shadow: 0 6px 14px rgba(0,0,0,0.35); }"
        ".judul-menu { font-size: 17px; color: #222222; }"
        ".keterangan { font-size: 8px; font-weight: bold; color: #222222; }"
        ".label-bawah { font-size: 10px; color: #222222; }"
        "separator { background: #c4c4c4; min-height: 1px; }";

    GtkCssProvider *prov = gtk_css_provider_new();
    gtk_css_provider_load_from_string(prov, css);
    gtk_style_context_add_provider_for_display(
        gdk_display_get_default(),
        GTK_STYLE_PROVIDER(prov),
        GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
    g_object_unref(prov);
}

static void on_activate(GtkApplication *app, gpointer user_data)
{
    pasang_css();

    GtkWidget *window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Menu Power");
    gtk_window_set_default_size(GTK_WINDOW(window), 420, 560);
    gtk_window_set_resizable(GTK_WINDOW(window), FALSE);

    /* Kartu utama di tengah jendela */
    GtkWidget *kartu = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_widget_add_css_class(kartu, "kartu");
    gtk_widget_set_halign(kartu, GTK_ALIGN_CENTER);
    gtk_widget_set_valign(kartu, GTK_ALIGN_CENTER);
    gtk_widget_set_size_request(kartu, 340, -1);

    /* Bagian atas: tiga item menu */
    gtk_box_append(GTK_BOX(kartu),
        make_menu_item("Power Off", NULL,
            make_icon(IKON_POWER, MERAH_TUA, PUTIH, 66)));

    gtk_box_append(GTK_BOX(kartu),
        make_menu_item("Reboot", NULL,
            make_icon(IKON_REBOOT, ORANYE, PUTIH, 66)));

    gtk_box_append(GTK_BOX(kartu),
        make_menu_item("Soft Reboot",
            "Simply restarts the Android UI by killing zygote process",
            make_icon(IKON_SOFT, KUNING, PUTIH, 66)));

    /* Garis pemisah */
    GtkWidget *garis = gtk_separator_new(GTK_ORIENTATION_HORIZONTAL);
    gtk_widget_set_margin_start(garis, 40);
    gtk_widget_set_margin_end(garis, 40);
    gtk_widget_set_margin_top(garis, 8);
    gtk_widget_set_margin_bottom(garis, 8);
    gtk_box_append(GTK_BOX(kartu), garis);

    /* Bagian bawah: tiga ikon sejajar */
    GtkWidget *bawah = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_box_set_homogeneous(GTK_BOX(bawah), TRUE);
    gtk_widget_set_margin_top(bawah, 8);
    gtk_widget_set_margin_bottom(bawah, 8);

    gtk_box_append(GTK_BOX(bawah),
        make_bottom_item("Recovery", IKON_RECOVERY, HIJAU, HITAM));
    gtk_box_append(GTK_BOX(bawah),
        make_bottom_item("Bootloader", IKON_BOOTLOADER, MERAH, HITAM));
    gtk_box_append(GTK_BOX(bawah),
        make_bottom_item("Safe Mode", IKON_SAFE, HITAM, HITAM));

    gtk_box_append(GTK_BOX(kartu), bawah);

    gtk_window_set_child(GTK_WINDOW(window), kartu);
    gtk_window_present(GTK_WINDOW(window));
}

int main(int argc, char **argv)
{
    GtkApplication *app = gtk_application_new("com.contoh.menupower",
                                              G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(on_activate), NULL);

    int status = g_application_run(G_APPLICATION(app), argc, argv);

    g_object_unref(app);
    return status;
}

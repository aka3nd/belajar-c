#include <gtk/gtk.h>

/* Callback: fungsi yang dipanggil saat tombol diklik */
static void on_clicked(GtkButton *button, gpointer data)
{
    g_print("Tombol ditekan!\n");
}

/* Dipanggil saat aplikasi diaktifkan (dibuka) */
static void on_activate(GtkApplication *app, gpointer user_data)
{
    /* 1. Buat jendela */
    GtkWidget *window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Halo GTK4");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 150);

    /* 2. Buat tombol dengan label */
    GtkWidget *button = gtk_button_new_with_label("Klik saya");

    /* 3. Hubungkan sinyal "clicked" ke fungsi callback */
    g_signal_connect(button, "clicked", G_CALLBACK(on_clicked), NULL);

    /* 4. Letakkan tombol di dalam jendela, lalu tampilkan */
    gtk_window_set_child(GTK_WINDOW(window), button);
    gtk_window_present(GTK_WINDOW(window));
}

int main(int argc, char **argv)
{
    /* Buat objek aplikasi dengan ID unik (format seperti nama domain terbalik) */
    GtkApplication *app = gtk_application_new("com.contoh.halo",
                                              G_APPLICATION_DEFAULT_FLAGS);

    /* Hubungkan sinyal "activate" ke fungsi on_activate */
    g_signal_connect(app, "activate", G_CALLBACK(on_activate), NULL);

    /* Jalankan loop event; program berhenti di sini sampai jendela ditutup */
    int status = g_application_run(G_APPLICATION(app), argc, argv);

    /* Bebaskan memori objek aplikasi */
    g_object_unref(app);
    return status;
}

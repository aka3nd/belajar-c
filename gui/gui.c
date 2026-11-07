#include <gtk/gtk.h>

/* Fungsi ini dipanggil saat aplikasi aktif (activate) */
static void on_activate(GtkApplication *app, gpointer user_data)
{
    GtkWidget *window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Halo GTK4");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 150);

    GtkWidget *button = gtk_button_new_with_label("Klik saya");
    gtk_window_set_child(GTK_WINDOW(window), button);

    gtk_window_present(GTK_WINDOW(window));
}

int main(int argc, char **argv)
{
    /* Membuat objek aplikasi dengan ID unik (format terbalik domain) */
    GtkApplication *app = gtk_application_new("com.contoh.halo",
                                              G_APPLICATION_DEFAULT_FLAGS);

    /* Menghubungkan sinyal "activate" dengan fungsi on_activate */
    g_signal_connect(app, "activate", G_CALLBACK(on_activate), NULL);

    /* Menjalankan loop aplikasi */
    int status = g_application_run(G_APPLICATION(app), argc, argv);

    g_object_unref(app);
    return status;
}

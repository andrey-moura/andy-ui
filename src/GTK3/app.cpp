// Include gtk
#include <gtk/gtk.h>

#include <andy/ui/app.hpp>

GtkApplication *gtkapp = nullptr;
andy::ui::app* andy_app = nullptr;

int argc = 0;
char** argv = nullptr;

void on_activate (GtkApplication* app, gpointer user_data) {
    andy_app = reinterpret_cast<andy::ui::app*>(user_data);
    andy_app->on_init(argc, argv);
}

andy::ui::app::app(std::string_view __name, std::string_view vendor)
{
    gtkapp = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
    g_set_application_name("My App");
    g_signal_connect (gtkapp, "activate", G_CALLBACK (on_activate), this);
}

andy::ui::app::~app()
{
}

int andy::ui::app::run(int __argc, char** __argv)
{
    argc = __argc;
    argv = __argv;

    int status = g_application_run (G_APPLICATION (gtkapp), 0, nullptr);

    g_object_unref (gtkapp);

    return 0;
}
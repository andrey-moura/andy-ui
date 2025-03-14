#include <andy/ui/frame.hpp>

//#include <uva/xml.hpp>

#include <iostream>

#include <andy/ui/app.hpp>
#include <uva/drawing/gtk3+-3.0.hpp>

#include <gtk/gtk.h>

extern GtkApplication *gtkapp;

struct window_data {
    GtkWidget* window;
};

namespace andy
{
    namespace ui
    {
        frame::frame(std::string_view __title)
        {
            GtkWidget* window = gtk_application_window_new (gtkapp);
            os_specific_data_as<window_data>().window = window;

            init(window, window, __title);
        }

        frame::~frame()
        {
            GtkWidget* window = os_specific_data_as<window_data>().window;
            gtk_widget_destroy(window);
        }

        void frame::show(bool maximized)
        {
            GtkWidget* window = os_specific_data_as<window_data>().window;

            if(maximized) {
                gtk_window_maximize(GTK_WINDOW(window));
            }

            gtk_widget_show_all(window);
        }
    }
}
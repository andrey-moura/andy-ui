#include <uva/ui/dialog.hpp>

//#include <uva/xml.hpp>

#include <iostream>

#include <uva/ui/app.hpp>
#include <uva/drawing/gtk3+-3.0.hpp>

#include <gtk/gtk.h>

struct window_data {
    GtkWidget* window;
};

#define m_dialog os_specific_data_as<window_data>().window

namespace uva
{
    namespace ui
    {
        dialog::dialog(std::string_view __title)
        {
            m_dialog = gtk_dialog_new();

            GtkWidget* content_area = gtk_dialog_get_content_area(GTK_DIALOG(m_dialog));

            init(content_area, m_dialog, __title);
        }

        dialog::~dialog()
        {
            gtk_widget_destroy(m_dialog);
        }

        void dialog::show(bool maximized)
        {
            GtkWidget* dialog = os_specific_data_as<window_data>().window;
            gtk_widget_show_all(m_dialog);
            gtk_dialog_run(GTK_DIALOG(m_dialog));
        }
    };
};
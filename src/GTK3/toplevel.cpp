#include <gtk/gtk.h>

#include <iostream>

#include <andy/ui/toplevel.hpp>
#include <andy/ui/app.hpp>

#include <uva/drawing/gtk3+-3.0.hpp>

struct window_data {
    GtkWidget* window;
};

#define m_widget os_specific_data_as<window_data>().window

void draw_callback(GtkWidget* widget, cairo_t* cr, gpointer data) {
    andy::ui::toplevel* top = reinterpret_cast<andy::ui::toplevel*>(data);
    uva::drawing::software_renderer renderer;
    renderer.os_specific_data_as<software_renderer_data>().cairo = cr;
    top->draw(renderer);
}

void motion_notify_event(GtkWidget* widget, GdkEventMotion* event, gpointer data) {
    andy::ui::toplevel* top = reinterpret_cast<andy::ui::toplevel*>(data);
    top->motion(uva::point(event->x, event->y));
}

void button_press_event(GtkWidget* widget, GdkEventButton* event, gpointer data) {
    andy::ui::toplevel* top = reinterpret_cast<andy::ui::toplevel*>(data);
    top->click(uva::point(event->x, event->y));
}

gboolean key_press_event(GtkWidget* widget, GdkEventKey* event, gpointer data) {
    andy::ui::toplevel* top = reinterpret_cast<andy::ui::toplevel*>(data);
    if(top->on_char(std::string(event->string))) {
        GtkWidget* dialog = top->os_specific_data_as<window_data>().window;
        gtk_widget_queue_draw(dialog);
    }

    return TRUE;
}

namespace andy
{
    namespace ui
    {
        toplevel::toplevel()
        {

        }

        toplevel::~toplevel()
        {
        }

        uva::size toplevel::size() const
        {
            GtkWidget* window = os_specific_data_as<window_data>().window;

            int width, height;
            gtk_window_get_size(GTK_WINDOW(window), &width, &height);

            return uva::size(width, height);
        }

        andy::ui::cursor_type toplevel::cursor() const
        {
            GtkWidget* window = os_specific_data_as<window_data>().window;
            GdkWindow *gdk_window = gtk_widget_get_window(GTK_WIDGET(window));

            GdkCursor* cursor = gdk_window_get_cursor(gdk_window);

            if(!cursor) {
                return andy::ui::cursor_type::default_cursor;
            }

            GdkCursorType cursor_type = gdk_cursor_get_cursor_type(cursor);

            switch(cursor_type) {
                case GDK_HAND2:
                    return andy::ui::cursor_type::pointer;
                default:
                    return andy::ui::cursor_type::default_cursor;
            }
        }

        void toplevel::set_cursor(cursor_type __cursor)
        {
            GtkWidget* window = os_specific_data_as<window_data>().window;
            GdkWindow *gdk_window = gtk_widget_get_window(GTK_WIDGET(window));

            GdkCursor* cursor = nullptr;

            switch(__cursor) {
                case andy::ui::cursor_type::default_cursor:
                    cursor = nullptr;
                    break;
                case andy::ui::cursor_type::pointer:
                    cursor = gdk_cursor_new_from_name(gdk_window_get_display(gdk_window), "pointer");
                    break;
                default:
                    break;
            }

            gdk_window_set_cursor(gdk_window, cursor);
        }

        void toplevel::init(void* __container, void* __window, std::string_view __title)
        {
            GtkWidget* window = (GtkWidget*)__window;
            GtkWidget* container = (GtkWidget*)__container;

            gtk_window_set_title(GTK_WINDOW(window), __title.data());
//            gtk_window_set_modal(GTK_WINDOW(window), TRUE);
            gtk_window_set_default_size (GTK_WINDOW (window), 400, 400);

            // GtkWidget* drawing_area = gtk_drawing_area_new();
            // gtk_widget_set_can_focus(drawing_area, TRUE);

            // gtk_container_add(GTK_CONTAINER(container), drawing_area);
            // gtk_widget_set_size_request(drawing_area, 400, 400);

            // g_signal_connect (drawing_area, "draw", G_CALLBACK (draw_callback), this);
            // g_signal_connect (drawing_area, "motion_notify_event", G_CALLBACK (motion_notify_event), this);
            // g_signal_connect (drawing_area, "button-press-event", G_CALLBACK (button_press_event), this);
            // g_signal_connect (drawing_area, "key_press_event", G_CALLBACK (key_press_event), this);
            
            // gtk_widget_add_events(drawing_area, GDK_BUTTON_PRESS_MASK);
            // gtk_widget_add_events(drawing_area, GDK_POINTER_MOTION_MASK);
        }
    };
};
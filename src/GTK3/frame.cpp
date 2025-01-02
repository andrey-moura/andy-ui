#include <uva/ui/frame.hpp>

//#include <uva/xml.hpp>

#include <iostream>

#include <uva/ui/app.hpp>
#include <uva/drawing/gtk3+-3.0.hpp>

#include <gtk/gtk.h>

extern GtkApplication *gtkapp;
extern uva::lang::ui::app* uvaapp;

struct window_data {
    GtkWidget* window;
};

void draw_callback(GtkWidget* widget, cairo_t* cr, gpointer data) {
    uva::lang::ui::frame* frame = reinterpret_cast<uva::lang::ui::frame*>(data);
    uva::drawing::software_renderer renderer;
    renderer.os_specific_data_as<software_renderer_data>().cairo = cr;
    frame->draw(renderer);
}

void motion_notify_event(GtkWidget* widget, GdkEventMotion* event, gpointer data) {
    uva::lang::ui::frame* frame = reinterpret_cast<uva::lang::ui::frame*>(data);
    frame->motion(uva::point(event->x, event->y));
}

uva::lang::ui::frame::frame(std::string_view __title)
{
    GtkWidget* window = gtk_application_window_new (gtkapp);

    gtk_window_set_title (GTK_WINDOW (window), __title.data());
    gtk_window_set_default_size (GTK_WINDOW (window), 400, 400);

    os_specific_data_as<window_data>().window = window;

    //g_signal_connect (window, "draw", G_CALLBACK (draw_callback), this);

    // Setup the drawing area

    GtkWidget* drawing_area = gtk_drawing_area_new();

    gtk_container_add(GTK_CONTAINER(window), drawing_area);

    g_signal_connect (drawing_area, "draw", G_CALLBACK (draw_callback), this);
    g_signal_connect (drawing_area, "motion_notify_event", G_CALLBACK (motion_notify_event), this);

    gtk_widget_add_events(drawing_area, GDK_POINTER_MOTION_MASK);
}

uva::lang::ui::frame::~frame()
{

}

void uva::lang::ui::frame::show(bool maximized)
{
    GtkWidget* window = os_specific_data_as<window_data>().window;

    if(maximized) {
        gtk_window_maximize(GTK_WINDOW(window));
    }

    gtk_widget_show_all(window);
}

void uva::lang::ui::frame::hide()
{

}

uva::size uva::lang::ui::frame::size() const
{
    GtkWidget* window = os_specific_data_as<window_data>().window;

    int width, height;
    gtk_window_get_size(GTK_WINDOW(window), &width, &height);

    return uva::size(width, height);
}

uva::lang::ui::cursor_type uva::lang::ui::frame::cursor() const
{
    GtkWidget* window = os_specific_data_as<window_data>().window;
    GdkWindow *gdk_window = gtk_widget_get_window(GTK_WIDGET(window));

    GdkCursor* cursor = gdk_window_get_cursor(gdk_window);

    if(!cursor) {
        return uva::lang::ui::cursor_type::default_cursor;
    }

    GdkCursorType cursor_type = gdk_cursor_get_cursor_type(cursor);

    switch(cursor_type) {
        case GDK_HAND2:
            return uva::lang::ui::cursor_type::pointer;
        default:
            return uva::lang::ui::cursor_type::default_cursor;
    }
}

void uva::lang::ui::frame::set_cursor(cursor_type __cursor)
{
    GtkWidget* window = os_specific_data_as<window_data>().window;
    GdkWindow *gdk_window = gtk_widget_get_window(GTK_WIDGET(window));

    GdkCursor* cursor = nullptr;

    switch(__cursor) {
        case uva::lang::ui::cursor_type::default_cursor:
            cursor = nullptr;
            break;
        case uva::lang::ui::cursor_type::pointer:
            cursor = gdk_cursor_new_from_name(gdk_window_get_display(gdk_window), "pointer");
            break;
        default:
            break;
    }

    gdk_window_set_cursor(gdk_window, cursor);
}
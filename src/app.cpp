#include <andy/ui/app.hpp>

#include <gtk/gtk.h>

namespace andy
{
    namespace ui
    {
        app::app()
        {
            gtk_init(nullptr, nullptr);
        }

        app::~app()
        {
            gtk_main_quit();
        }

        void app::run()
        {
            on_init();
            gtk_main();
        }

        void app::on_init()
        {
            // To be overridden by subclasses
        }
    }
};
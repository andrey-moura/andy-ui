#include <andy/ui/app.hpp>

#include <Windows.h>

namespace andy
{
    namespace ui
    {
        app::app()
        {
        }

        app::~app()
        {
        }

        void app::run()
        {
            on_init();
        }

        void app::on_init()
        {
            // To be overridden by subclasses
        }
    }
};
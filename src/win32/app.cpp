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
            MSG msg;
            while (GetMessage(&msg, nullptr, 0, 0))
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }

        void app::on_init()
        {
            // To be overridden by subclasses
        }
    }
};
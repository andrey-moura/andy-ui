#include <windows.h>
#include <andy/ui/app.hpp>

andy::ui::app* uvaapp = nullptr;

HINSTANCE hInstance = nullptr;
HINSTANCE hPrevInstance = nullptr;
LPSTR lpCmdLine = nullptr;
int nCmdShow = 0;

andy::ui::app::app(std::string_view __name, std::string_view vendor)
{
}

andy::ui::app::~app()
{
    
}

int andy::ui::app::run(int _argc, char** _argv)
{
    on_init(_argc, _argv);

    MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
#include <windows.h>

#include <stdexcept>
#include <map>

#include <uva/ui/frame.hpp>
#include <uva/ui/app.hpp>

#include <uva/drawing/win32.hpp>
#include <uva/drawing.hpp>

extern uva::ui::app* uvaapp;

extern HINSTANCE hInstance;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    uva::ui::frame* frame = (uva::ui::frame*)GetWindowLongPtr(hwnd, GWLP_USERDATA);

    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    case WM_CREATE:
        {
            CREATESTRUCT* create = (CREATESTRUCT*)lParam;
            frame = (uva::ui::frame*)create->lpCreateParams;
            SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)frame);
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            uva::drawing::software_renderer renderer;
            renderer.os_specific_data_as<software_renderer_data>().dc = hdc;
            frame->draw(renderer);

            EndPaint(hwnd, &ps);
        }
        return 0;

    }

    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

namespace uva
{
    namespace ui
    {
        frame::frame(std::string_view __title)
        {
            const TCHAR* class_name = TEXT("uva::ui::frame");

            WNDCLASS wc = { 0 };
            wc.lpfnWndProc = WindowProc;
            wc.hInstance = hInstance;
            wc.lpszClassName = class_name;

            RegisterClass(&wc);

            HWND hwnd = CreateWindowEx(
                0, // Optional window styles.
                class_name,
                __title.data(),
                WS_OVERLAPPEDWINDOW, // Window style
                CW_USEDEFAULT, // X
                CW_USEDEFAULT, // Y
                CW_USEDEFAULT, // Width
                CW_USEDEFAULT, // Height
                nullptr, // Parent window
                nullptr, // Menu
                hInstance, // Instance handle
                this // Additional application data
            );

            if(hwnd == nullptr) {
                throw std::runtime_error("Failed to create window");
            }

            os_specific_data_as<window_data>().hwnd = hwnd;
        }

        frame::~frame()
        {

        }

        void frame::show(bool maximized)
        {
            HWND hwnd = os_specific_data_as<window_data>().hwnd;

            ShowWindow(hwnd, maximized ? SW_MAXIMIZE : SW_SHOW);
            UpdateWindow(hwnd);
        }
    }
}
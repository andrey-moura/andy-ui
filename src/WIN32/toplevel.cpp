#include <uva/ui/toplevel.hpp>

#include <Windows.h>

#include <uva/drawing/win32.hpp>

namespace uva
{
    namespace ui
    {
        toplevel::toplevel()
        {
        }

        toplevel::~toplevel()
        {
        }

        void toplevel::init(void* __container, void* __window, std::string_view __title)
        {
        }

        uva::size toplevel::size() const
        {
            HWND hwnd = os_specific_data_as<window_data>().hwnd;

            RECT rect;
            GetClientRect(hwnd, &rect);

            return uva::size(rect.right - rect.left, rect.bottom - rect.top);
        }

        void toplevel::set_cursor(cursor_type __cursor)
        {
        }

        cursor_type toplevel::cursor() const
        {
            return cursor_type::default_cursor;
        }
    };
};
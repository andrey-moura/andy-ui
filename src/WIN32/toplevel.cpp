#include <uva/ui/toplevel.hpp>

#include <Windows.h>

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
            return uva::size();
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
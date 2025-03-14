#pragma once

#include <uva/point.hpp>
#include <uva/size.hpp>
#include <uva/os_specific_data_member.hpp>
#include <uva/drawing.hpp>

namespace andy
{
    namespace ui
    {
        enum class cursor_type : uint8_t {
            default_cursor,
            pointer,
            max
        };
        class toplevel : public os_specific_data_member<32>
        {
        public:
            toplevel();
            ~toplevel();
        protected:
            void init(void* __container, void* __window, std::string_view __title);
        public:
            uva::size size() const;
            void set_cursor(cursor_type __cursor);
            cursor_type cursor() const;
        public:
            virtual void show(bool maximized = false) { }
        public:
            virtual void render() { }
            virtual void motion(uva::point __point) {}
            virtual void click(uva::point __point) {}
            virtual void draw(uva::drawing::basic_renderer& renderer) {}
            virtual bool on_char(std::string c) { return false; }
        };
    };
};
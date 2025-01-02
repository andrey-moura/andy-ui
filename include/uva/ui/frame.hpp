#pragma once

#include <cstddef>
#include <cstdint>

#include <string>
#include <string_view>

#include <uva/size.hpp>
#include <uva/os_specific_data_member.hpp>
#include <uva/drawing.hpp>

namespace uva
{
    namespace lang
    {
        namespace ui
        {
            enum class cursor_type : uint8_t {
                default_cursor,
                pointer,
                max
            };
            class frame : public os_specific_data_member<32>
            {
            public:
                frame(std::string_view __title);
                ~frame();
            public:
                void show(bool maximized = false);
                void hide();
            // Acessors
            public:
                uva::size size() const;
                cursor_type cursor() const;
            // Setters
            public:
                void set_cursor(cursor_type __cursor);
            public:
                virtual void render() { }
                virtual void motion(uva::point __point) {}
                virtual void draw(uva::drawing::basic_renderer& renderer) {}
            };
        };
    }
};
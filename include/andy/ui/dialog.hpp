#pragma once

#include <cstddef>
#include <cstdint>

#include <string>
#include <string_view>

#include <uva/size.hpp>
#include <uva/os_specific_data_member.hpp>
#include <uva/drawing.hpp>

#include <andy/ui/toplevel.hpp>

namespace andy
{
    namespace ui
    {
        class dialog : public toplevel
        {
        public:
            dialog(std::string_view __title);
            ~dialog();
        public:
            void show(bool maximized = false) override;
        };
    };
};
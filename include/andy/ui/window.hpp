#pragma once

#include "andy/drawing/window.hpp"

namespace andy
{
    namespace ui
    {
        class window : public andy::drawing::window
        {
        public:
            window(std::string_view title)
                : andy::drawing::window(title)
            {
            }
        };
    };
};

#pragma once

#include <cstddef>
#include <cstdint>

#include <string>
#include <string_view>

#include <uva/size.hpp>

namespace andy
{
    namespace ui
    {
        class frame
        {
        public:
            frame(std::string_view __title);
            ~frame();
        public:
            virtual void show(bool maximized = false);
        private:
            void* m_data = nullptr;
        };
    };
};
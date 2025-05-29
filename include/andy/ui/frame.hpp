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
        class app;
        class frame
        {
        public:
            frame(std::string_view __title);
            ~frame();
        public:
            void show(bool maximized = false);
        public:
            uva::size size() const;
        protected:
            virtual void on_draw() {};
        protected:
            void* m_data = nullptr;
        public:
            friend class app;
        };
    };
};
#pragma once

#include <string>
#include <string_view>
#include <functional>

#include <andy/os_specific_data_member.hpp>
#include <andy/ui/implmement_app.hpp>

namespace andy
{
    namespace ui
    {
        class app : public os_specific_data_member<32>
        {
        public:
            app(std::string_view __name, std::string_view vendor);
            ~app();
        public:
            int run(int argc, char** argv);
        protected:
            virtual void on_init(int argc, char** argv) = 0;
        private:
            struct app_impl;
            app_impl* m_impl = nullptr;
        };
    };
};
#pragma once

#include <string>
#include <string_view>
#include <functional>

#include <uva/ui/os_specific_data_member.hpp>
#include <uva/ui/implmement_app.hpp>

namespace uva
{
    namespace lang
    {
        namespace ui
        {
            class app : public os_specific_data_member
            {
            public:
                app(std::string_view __name, std::string_view vendor);
                ~app();
            public:
                int run(int argc, char** argv);
            public:
                virtual void on_init(int argc, char** argv) = 0;
            };
        };
    };
};
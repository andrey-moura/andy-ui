#include <map>

#include "andy/ui/app.hpp"

#include "app_impl.hpp"

namespace andy
{
    namespace ui
    {
        app::app(std::string_view __name, std::string_view vendor)
            : m_impl(new app_impl())
        {
        }
        
        app::~app()
        {
            delete m_impl;
            m_impl = nullptr;
        }

        int app::run(int argc, char** argv)
        {
            m_impl->init(argc, argv);
            on_init(argc, argv);
            m_impl->run(argc, argv);
        }
    }
}
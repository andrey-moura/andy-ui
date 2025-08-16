#include "andy/ui/xml_page.hpp"

#include <iostream>

namespace andy
{
    namespace ui
    {
        xml_page::xml_page(
            std::shared_ptr<andy::xml> xml,
            std::shared_ptr<andy::widgets::layout> layout,
            std::shared_ptr<andy::xml::schema> schema
        ) : m_xml(std::move(xml)), m_layout(std::move(layout)), page()
        {
        }

        xml_page::~xml_page()
        {
        }

        void xml_page::draw()
        {
        }
    }
}
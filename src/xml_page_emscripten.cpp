#include <andy/ui/xml_page.hpp>

#include <iostream>

#include <emscripten/emscripten.h>

namespace andy
{
    namespace ui
    {
        xml_page::xml_page(std::string __xml)
            : m_xml(andy::xml::decode(std::move(__xml)))
        {
        }

        xml_page::~xml_page()
        {
        }

        void xml_page::draw()
        {
            emscripten_run_script("draw_xml_page(\' + m_xml.source + \');");
        }
    }
}
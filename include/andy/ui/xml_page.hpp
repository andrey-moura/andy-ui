#pragma once

#include <string_view>

#include "page.hpp"

#include "andy/widgets.hpp"
#include "andy/xml.hpp"
#include "andy/drawing.hpp"

namespace andy
{
    namespace ui
    {
        class xml_page : public page
        {
        public:
            xml_page(
                std::shared_ptr<andy::xml> xml,
                std::shared_ptr<andy::widgets::layout> layout,
                std::shared_ptr<andy::xml::schema> schema = nullptr
            );
            ~xml_page();
        protected:
            virtual void draw() override;
        private:
            std::shared_ptr<andy::xml> m_xml;
            std::shared_ptr<andy::widgets::layout> m_layout;
        };
    }
}
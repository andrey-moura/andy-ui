#include <memory>

namespace uva
{
    namespace lang
    {
        class interpreter;
        class structure;

        namespace frame_class
        {
            std::shared_ptr<andy::lang::structure> create(andy::lang::interpreter* interpreter);
        };
    };
};
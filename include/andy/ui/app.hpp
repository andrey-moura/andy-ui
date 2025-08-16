#pragma once

namespace andy
{
    namespace ui
    {
        class app
        {
        public:
            app();
            ~app();
        protected:
            void run();
            virtual void on_init();
        };
    }
};
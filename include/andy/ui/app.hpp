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
        public:
            void run();
        protected:
            virtual void on_init();
        };
    }
};
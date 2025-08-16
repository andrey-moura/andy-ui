#include "app_impl.hpp"

#ifdef ANDY_DRAWING_SDL3
    #include <SDL3/SDL.h>
#endif

namespace andy
{
    namespace ui
    {
        app::app_impl::app_impl()
        {

        }

        void app::app_impl::init(int argc, char** argv)
        {
            if (SDL_Init(SDL_INIT_VIDEO) < 0) {
                std::string error = SDL_GetError();
                throw std::runtime_error("Failed to initialize SDL: " + error);
            }
        }

        void app::app_impl::run(int argc, char** argv)
        {
            SDL_Event event;
            bool running = true;

            while (running) {
                while (SDL_PollEvent(&event)) {
                    if (event.type == SDL_EVENT_QUIT) {
                        running = false;
                    }
                }

                SDL_Delay(16);
            }

            SDL_Quit();
        }
    }
}

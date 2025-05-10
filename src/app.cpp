#include "andy/ui/app.hpp"

#include <SDL3/SDL.h>

namespace andy
{
    namespace ui
    {
        app::app(std::string_view __name, std::string_view vendor)
        {
        }
        
        app::~app()
        {
        }

        int app::run(int argc, char** argv)
        {
            SDL_Init(SDL_INIT_VIDEO);

            on_init(argc, argv);

            while(true) {
                SDL_Event event;
                while(SDL_PollEvent(&event)) {
                    if(event.type == SDL_EVENT_QUIT) {
                        return 0;
                    }
                }

                // Update and render your application here

                SDL_Delay(16); // Simulate a frame delay
            }
        }
    }
}
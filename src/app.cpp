#include <map>

#include "andy/ui/app.hpp"
#include "andy/ui/frame.hpp"

#include <SDL3/SDL.h>

extern std::map<SDL_WindowID, andy::ui::frame*> g_window_id_to_frame;

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
                    switch(event.type) {
                        case SDL_EVENT_WINDOW_EXPOSED: {
                            auto frame = g_window_id_to_frame[event.window.windowID];
                            if(frame) {
                                frame->on_draw();
                            }
                            break;
                        }
                        case SDL_EVENT_QUIT:
                            SDL_Quit();
                            return 0;
                    }
                }

                // Update and render your application here

                SDL_Delay(16); // Simulate a frame delay
            }
        }
    }
}
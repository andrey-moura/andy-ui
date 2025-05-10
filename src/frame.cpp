#include <stdexcept>
#include <map>

#include "andy/ui/frame.hpp"

#include <SDL3/SDL.h>

#define m_window (SDL_Window*)m_data

namespace andy
{
    namespace ui
    {
        frame::frame(std::string_view __title)
        {
            m_data = SDL_CreateWindow(__title.data(), 600, 400, SDL_WINDOW_HIDDEN | SDL_WINDOW_RESIZABLE);
            if(!m_window) {
                throw std::runtime_error("Failed to create window.");
            }
        }

        frame::~frame()
        {
            SDL_DestroyWindow(m_window);
        }

        void frame::show(bool maximized)
        {
            if(maximized) {
                SDL_MaximizeWindow(m_window);
            }
            SDL_ShowWindow(m_window);
        }
    }
}
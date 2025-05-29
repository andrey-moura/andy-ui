#include <stdexcept>
#include <map>

#include "andy/ui/frame.hpp"

#include <SDL3/SDL.h>

#define m_window (SDL_Window*)m_data

std::map<SDL_WindowID, andy::ui::frame*> g_window_id_to_frame;

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
            SDL_WindowID id = SDL_GetWindowID(m_window);
            g_window_id_to_frame[id] = this;
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

        uva::size frame::size() const
        {
            int w, h;
            SDL_GetWindowSize(m_window, &w, &h);
            return { w, h };
        }
    }
}
#pragma once

#include <SDL.h>
#include <string>

namespace roguey {
    class WindowSystem {
    public:
        WindowSystem(int screenWidth, int screenHeight, const std::string &title);

        ~WindowSystem();

        [[nodiscard]] SDL_Renderer *createRenderer() const;

    private:
        SDL_Window *window;
    };
}

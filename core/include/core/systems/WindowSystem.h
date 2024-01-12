#pragma once

#include <SDL.h>

namespace roguey {
    class WindowSystem {
    public:
        WindowSystem(int screenWidth, int screenHeight, const char *title);

        ~WindowSystem();

        SDL_Renderer *createRenderer();

    private:
        SDL_Window *window;
    };
}

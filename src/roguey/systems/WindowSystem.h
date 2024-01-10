//
// Created by Tim Heuett on 1/9/24.
//

#ifndef ROGUEY_V4_WINDOWSYSTEM_H
#define ROGUEY_V4_WINDOWSYSTEM_H


#include <SDL.h>

namespace roguey {
    class WindowSystem {
    public:
        WindowSystem(int screenWidth, int screenHeight, const char *title);
        ~WindowSystem();
        SDL_Renderer* createRenderer();

    private:
        SDL_Window *window;
    };
}


#endif //ROGUEY_V4_WINDOWSYSTEM_H

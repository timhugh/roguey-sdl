#include "core/systems/WindowSystem.h"
#include <iostream>

roguey::WindowSystem::WindowSystem(int screenWidth, int screenHeight, const char *title) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout << "Failed to init SDL: " << SDL_GetError() << std::endl;
        return;
    }

    window = SDL_CreateWindow("Hello World",
                                          SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                          640, 480, SDL_WINDOW_RESIZABLE);

    if (window == nullptr) {
        std::cout << "Failed to create SDL window: " << SDL_GetError() << std::endl;
        return;
    }
}

SDL_Renderer *roguey::WindowSystem::createRenderer() {
    return SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

roguey::WindowSystem::~WindowSystem() {
    SDL_DestroyWindow(window);
    SDL_Quit();
}


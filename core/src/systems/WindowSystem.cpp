#include "core/systems/WindowSystem.h"
#include <iostream>

roguey::systems::WindowSystem::WindowSystem(const int screenWidth, const int screenHeight, const std::string &title) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout << "Failed to init SDL: " << SDL_GetError() << std::endl;
        return;
    }

    window = SDL_CreateWindow(title.c_str(),
                              SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                              screenWidth, screenHeight, SDL_WINDOW_RESIZABLE);

    if (window == nullptr) {
        std::cout << "Failed to create SDL window: " << SDL_GetError() << std::endl;
        return;
    }
}

std::shared_ptr<SDL_Renderer> roguey::systems::WindowSystem::createRenderer() const {
    return {
            SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED),
            SDL_DestroyRenderer
    };
}

roguey::systems::WindowSystem::~WindowSystem() {
    SDL_DestroyWindow(window);
    SDL_Quit();
}


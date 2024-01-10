//
// Created by Tim Heuett on 1/9/24.
//

#include "RenderSystem.h"

#include <SDL_image.h>
#include <string>

namespace roguey {
    SDL_Texture* texture;

    RenderSystem::RenderSystem(WindowSystem *windowSystem) {
        renderer = windowSystem->createRenderer();

        const int imgFlags = IMG_INIT_PNG;
        if (!(IMG_Init(imgFlags) & imgFlags)) {
            throw std::runtime_error(
                    "SDL_image could not initialize! SDL_image Error: " +
                    std::string(IMG_GetError()));
        }

        // TODO: temp
        texture = IMG_LoadTexture(renderer, "assets/graphics/sprites.png");
        if (texture == nullptr) {
            throw std::runtime_error(
                    "SDL_image could not create texture! SDL_image Error: " +
                    std::string(IMG_GetError()));
        }
    }

    RenderSystem::~RenderSystem() {
        IMG_Quit();
        SDL_DestroyRenderer(renderer);
    }

    void RenderSystem::render() {
        SDL_RenderClear(renderer);

        SDL_RenderCopy(renderer, texture, nullptr, nullptr);

        SDL_RenderPresent(renderer);
    }
}

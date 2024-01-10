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
        assetLoader = new services::AssetLoader(renderer, "../assets/");

        // TODO: temp
        texture = assetLoader->loadTexture("graphics/sprites.png");
    }

    RenderSystem::~RenderSystem() {
        delete assetLoader;
        SDL_DestroyTexture(texture);
        SDL_DestroyRenderer(renderer);
    }

    void RenderSystem::render() {
        SDL_RenderClear(renderer);

        SDL_RenderCopy(renderer, texture, nullptr, nullptr);

        SDL_RenderPresent(renderer);
    }
}

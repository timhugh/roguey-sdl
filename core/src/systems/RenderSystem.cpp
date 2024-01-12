#include "core/systems/RenderSystem.h"

#include <SDL_image.h>
#include <string>

namespace roguey {
    SDL_Texture *texture;

    RenderSystem::RenderSystem(WindowSystem *windowSystem) {
        renderer = windowSystem->createRenderer();
        textureLoader = new services::TextureLoader(renderer, "../assets/");
    }

    RenderSystem::~RenderSystem() {
        delete textureLoader;
        SDL_DestroyRenderer(renderer);
    }

    void RenderSystem::render() const {
        SDL_RenderClear(renderer);

        // TODO: call other renderers

        SDL_RenderPresent(renderer);
    }
}

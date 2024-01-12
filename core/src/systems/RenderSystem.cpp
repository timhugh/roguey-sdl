#include "core/systems/RenderSystem.h"

#include <SDL_image.h>
#include <string>

namespace roguey {
    SDL_Texture *texture;

    RenderSystem::RenderSystem(WindowSystem *windowSystem) {
        renderer = windowSystem->createRenderer();
        textureLoader = std::make_unique<services::TextureLoader>(renderer, "../assets/");
    }

    void RenderSystem::render() const {
        // TODO: call other renderers

        SDL_RenderPresent(renderer.get());
    }
}

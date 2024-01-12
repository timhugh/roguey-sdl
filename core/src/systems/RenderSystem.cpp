#include "core/systems/RenderSystem.h"
#include "core/Drawable.h"

#include <SDL_image.h>

namespace roguey::systems {
    RenderSystem::RenderSystem(
            std::shared_ptr<SDL_Renderer> renderer,
            std::shared_ptr<systems::LevelRenderSystem> levelRenderSystem
    ) {
        this->renderer = renderer;
        this->levelRenderSystem = levelRenderSystem;
    }

    void RenderSystem::render() const {
        levelRenderSystem->render();
        SDL_RenderPresent(renderer.get());
    }
}

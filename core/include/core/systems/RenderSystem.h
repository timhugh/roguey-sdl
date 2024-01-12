#pragma once

#include "WindowSystem.h"
#include "core/services/TextureLoader.h"
#include "core/systems/LevelRenderSystem.h"

namespace roguey::systems {
    class RenderSystem {
    public:
        RenderSystem(
                std::shared_ptr<SDL_Renderer> renderer,
                std::shared_ptr<LevelRenderSystem> levelRenderSystem
        );

        void render() const;

    private:
        std::shared_ptr<systems::LevelRenderSystem> levelRenderSystem;
        std::shared_ptr<SDL_Renderer> renderer;
    };
}

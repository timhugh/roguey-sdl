#pragma once

#include <SDL.h>
#include <memory>
#include "core/Level.h"

namespace roguey::systems {
    class LevelRenderSystem {
    public:
        LevelRenderSystem(const std::shared_ptr<SDL_Renderer> &renderer, const std::shared_ptr<Level> &level);

        ~LevelRenderSystem();

        void render() const;

    private:
        const std::shared_ptr<SDL_Renderer> renderer;
        const std::shared_ptr<Level> level;
        const int tilesize = 32;
        const int cameraX = 0;
        const int cameraY = 0;
    };
}

#pragma once

#include <SDL.h>
#include <memory>

namespace roguey::services {
    class LevelRenderSystem {
    public:
        explicit LevelRenderSystem(const std::shared_ptr<SDL_Renderer> &renderer);

        ~LevelRenderSystem();

        void render() const;

    private:
        const std::shared_ptr<SDL_Renderer> renderer;
    };
}

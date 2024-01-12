#pragma once

#include <SDL.h>

namespace roguey::services {
    class LevelRenderSystem {
    public:
        LevelRenderSystem(SDL_Renderer *renderer);

        ~LevelRenderSystem();

        void render() const;

    private:
        SDL_Renderer *renderer;
    };
}

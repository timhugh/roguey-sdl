#pragma once

#include "WindowSystem.h"
#include "core/services/AssetLoader.h"

namespace roguey {
    class RenderSystem {
    public:
        explicit RenderSystem(WindowSystem *windowSystem);
        ~RenderSystem();
        void render();
    private:
        services::AssetLoader *assetLoader;
        SDL_Renderer *renderer;
    };
}

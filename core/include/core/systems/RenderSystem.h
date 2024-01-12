#pragma once

#include "WindowSystem.h"
#include "core/services/TextureLoader.h"

namespace roguey {
    class RenderSystem {
    public:
        explicit RenderSystem(WindowSystem *windowSystem);

        ~RenderSystem();

        void render() const;

    private:
        services::TextureLoader *textureLoader;
        SDL_Renderer *renderer;
    };
}

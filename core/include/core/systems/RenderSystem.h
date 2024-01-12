#pragma once

#include "WindowSystem.h"
#include "core/services/TextureLoader.h"

namespace roguey {
    class RenderSystem {
    public:
        explicit RenderSystem(WindowSystem *windowSystem);

        void render() const;

    private:
        std::unique_ptr<services::TextureLoader> textureLoader;
        std::shared_ptr<SDL_Renderer> renderer;
    };
}

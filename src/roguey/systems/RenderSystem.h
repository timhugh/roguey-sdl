//
// Created by Tim Heuett on 1/9/24.
//

#ifndef ROGUEY_V4_RENDERSYSTEM_H
#define ROGUEY_V4_RENDERSYSTEM_H

#include "WindowSystem.h"

namespace roguey {
    class RenderSystem {
    public:
        explicit RenderSystem(WindowSystem *windowSystem);
        ~RenderSystem();
        void render();
    private:
        SDL_Renderer *renderer;
    };
}


#endif //ROGUEY_V4_RENDERSYSTEM_H
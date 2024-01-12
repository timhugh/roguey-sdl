#pragma once

#include "systems/WindowSystem.h"
#include "systems/InputSystem.h"
#include "systems/FrameTimerSystem.h"
#include "systems/RenderSystem.h"

namespace roguey {

    class Game {
    public:
        Game();

        ~Game();

        void run();

    private:
        FrameTimerSystem *frameTimer;
        WindowSystem *window;
        RenderSystem *renderer;
        InputSystem *input;
    };

}
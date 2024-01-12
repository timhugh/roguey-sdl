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
        systems::FrameTimerSystem *frameTimerSystem;
        systems::WindowSystem *windowSystem;
        systems::RenderSystem *renderSystem;
        systems::InputSystem *inputSystem;
    };

}
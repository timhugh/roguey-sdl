//
// Created by Tim Heuett on 1/9/24.
//

#ifndef ROGUEY_V4_GAME_H
#define ROGUEY_V4_GAME_H

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
        FrameTimerSystem* frameTimer;
        WindowSystem* window;
        RenderSystem* renderer;
        InputSystem* input;
    };

} // roguey

#endif //ROGUEY_V4_GAME_H

//
// Created by Tim Heuett on 1/9/24.
//

#include "Game.h"
#include "systems/WindowSystem.h"
#include "systems/RenderSystem.h"
#include "systems/InputSystem.h"
#include "systems/FrameTimerSystem.h"
#include <iostream>

namespace roguey {
    void Game::run() {
        while (!input->shouldQuit()) {
            frameTimer->startFrame();

            input->update();
            renderer->render();

            frameTimer->endFrame();
        }
    }

    Game::Game() {
        frameTimer = new FrameTimerSystem(30);
        window = new WindowSystem(800, 600, "roguey");
        renderer = new RenderSystem(window);
        input = new InputSystem();
    }

    Game::~Game() {
        delete frameTimer;
        delete window;
        delete renderer;
        delete input;
    }
} // roguey
#include "core/Game.h"
#include "core/systems/WindowSystem.h"
#include "core/systems/RenderSystem.h"
#include "core/systems/InputSystem.h"
#include "core/systems/FrameTimerSystem.h"
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
}
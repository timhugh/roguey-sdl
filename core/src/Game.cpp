#include "core/Game.h"
#include "core/systems/WindowSystem.h"
#include "core/systems/RenderSystem.h"
#include "core/systems/InputSystem.h"
#include "core/systems/FrameTimerSystem.h"
#include "core/services/LevelLoader.h"
#include "core/services/TilesetLoader.h"
#include "core/Level.h"
#include <iostream>
#include <memory>

namespace roguey {

    static const std::string levelPath = "levels/test.json";
    static const std::string tilesetPath = "graphics/sprites.json";
    static const std::string assetPath = "../assets/";

    Game::Game() {
        frameTimerSystem = new systems::FrameTimerSystem(30);
        windowSystem = new systems::WindowSystem(800, 600, "roguey");
        inputSystem = new systems::InputSystem();

        services::LevelLoader levelLoader(assetPath);
        auto levelData = levelLoader.load(levelPath);

        services::TilesetLoader tilesetLoader(assetPath);
        auto tilesetData = tilesetLoader.load(tilesetPath);

        auto renderer = windowSystem->createRenderer();
        auto textureLoader = std::make_shared<TextureLoader>(TextureLoader(renderer, assetPath));
        auto level = std::make_shared<Level>(levelData, tilesetData, textureLoader);
        auto levelRenderSystem = std::make_shared<systems::LevelRenderSystem>(renderer, level);
        renderSystem = new systems::RenderSystem(renderer, levelRenderSystem);
    }

    void Game::run() {
        while (!inputSystem->shouldQuit()) {
            frameTimerSystem->startFrame();

            inputSystem->update();
            renderSystem->render();

            frameTimerSystem->endFrame();
        }
    }

    Game::~Game() {
        delete frameTimerSystem;
        delete windowSystem;
        delete renderSystem;
        delete inputSystem;
    }

}
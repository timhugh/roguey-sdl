#include "core/systems/LevelRenderSystem.h"

namespace roguey::services {

    LevelRenderSystem::LevelRenderSystem(const std::shared_ptr<SDL_Renderer> &renderer) : renderer(renderer) {}

    LevelRenderSystem::~LevelRenderSystem() = default;

    void LevelRenderSystem::render() const {
        SDL_SetRenderDrawColor(renderer.get(), 0, 0, 0, 255);
        SDL_RenderClear(renderer.get());
    }

}
#include "core/systems/LevelRenderSystem.h"

namespace roguey::systems {

    LevelRenderSystem::LevelRenderSystem(const std::shared_ptr<SDL_Renderer> &renderer,
                                         const std::shared_ptr<Level> &level) : renderer(renderer), level(level) {
    }

    LevelRenderSystem::~LevelRenderSystem() = default;

    void LevelRenderSystem::render() const {
        SDL_SetRenderDrawColor(renderer.get(), level->color.r, level->color.g, level->color.b, 255);
        SDL_RenderClear(renderer.get());

        for (int x = 0; x < level->tiles.size(); x++) {
            for (int y = 0; y < level->tiles[x].size(); y++) {
                level->tiles[x][y].draw(
                        renderer,
                        {(x + cameraX) * tilesize, (y + cameraY) * tilesize, tilesize, tilesize});
            }
        }

        for (auto &entity: level->entities) {
            entity.draw(renderer,
                        {(entity.x + cameraX) * tilesize, (entity.y + cameraY) * tilesize, tilesize, tilesize});
        }
    }
}
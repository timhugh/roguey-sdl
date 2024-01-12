#include "core/Level.h"
#include "core/Color.h"

namespace roguey {

    Color convertHex(const std::string &hexColor) {
        unsigned long value = std::stoul(hexColor, nullptr, 16);

        Color color{
                (value >> 16) & 0xFF,
                (value >> 8) & 0xFF,
                value & 0xFF
        };
        return color;
    }

    SDL_Rect buildRect(int x, int y, int tilesize) {
        return SDL_Rect{x * tilesize, y * tilesize, tilesize, tilesize};
    }

    Level::Level(const std::shared_ptr<LevelLoader::LevelData> &levelData,
                 const std::shared_ptr<TilesetLoader::TilesetData> &tilesetData,
                 const std::shared_ptr<TextureLoader> &textureLoader) {

        auto texture = textureLoader->load(tilesetData->spritesheet);
        auto tilesize = tilesetData->tilesize;

        for (int y = 0; y < levelData->height; y++) {
            std::vector row = std::vector<Drawable>();
            for (int x = 0; x < levelData->width; x++) {
                auto tileData = levelData->baseTiles[x][y];
                auto spriteData = tilesetData->getTile(tileData);

                auto tile = Drawable(
                        texture,
                        x, y,
                        buildRect(spriteData->x, spriteData->y, tilesize)
                );
                row.push_back(tile);
            }
            tiles.push_back(row);
        }

        for (auto &entityData: levelData->entities) {
            auto spriteData = tilesetData->getTile(entityData.sprite);
            auto entity = Drawable(texture, entityData.x, entityData.y,
                                   buildRect(spriteData->x, spriteData->y, tilesize));
            entities.push_back(entity);
        }

        color = convertHex(tilesetData->baseColorHex);
    }
}
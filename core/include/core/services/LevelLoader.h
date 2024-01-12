#pragma once

#include <string>
#include <vector>
#include <nlohmann/json.hpp>

namespace roguey::services {
    struct Entity {
        std::string type;
        std::string sprite;
        int x;
        int y;

        bool operator==(const Entity &other) const {
            return type == other.type &&
                   sprite == other.sprite &&
                   x == other.x &&
                   y == other.y;
        }

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(Entity, type, sprite, x, y);
    };

    struct Level {
        std::string name;
        int width;
        int height;
        std::string baseColorHex;
        std::vector<std::vector<int>> baseTiles;
        std::vector<Entity> entities;

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(Level, name, width, height, baseColorHex, baseTiles, entities);
    };

    class LevelLoader {
    public:
        explicit LevelLoader(std::string baseAssetPath);

        Level load(std::string path) const;

    private:
        std::string baseAssetPath;
    };
}

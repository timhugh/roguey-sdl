#pragma once

#include <string>
#include <vector>
#include <nlohmann/json.hpp>

namespace roguey::services {

    class LevelLoader {
    public:

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

        explicit LevelLoader(const std::string &baseAssetPath);

        [[nodiscard]] std::unique_ptr<Level> load(const std::string &path) const;

    private:
        const std::string baseAssetPath;
    };
}

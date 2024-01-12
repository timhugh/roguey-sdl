#pragma once

#include <string>
#include <vector>
#include <nlohmann/json.hpp>

namespace roguey::services {

    class LevelLoader {
    public:

        struct EntityData {
            std::string type;
            std::string sprite;
            int x;
            int y;

            bool operator==(const EntityData &other) const {
                return type == other.type &&
                       sprite == other.sprite &&
                       x == other.x &&
                       y == other.y;
            }

            NLOHMANN_DEFINE_TYPE_INTRUSIVE(EntityData, type, sprite, x, y);
        };

        struct LevelData {
            std::string name;
            int width;
            int height;
            std::vector<std::vector<int>> baseTiles;
            std::vector<EntityData> entities;

            NLOHMANN_DEFINE_TYPE_INTRUSIVE(LevelData, name, width, height, baseTiles, entities);
        };

        explicit LevelLoader(const std::string &baseAssetPath);

        [[nodiscard]] std::shared_ptr<LevelData> load(const std::string &path) const;

    private:
        const std::string baseAssetPath;
    };
}

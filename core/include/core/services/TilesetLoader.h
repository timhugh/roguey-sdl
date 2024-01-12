#pragma once

#include <string>
#include <map>
#include <nlohmann/json.hpp>

namespace roguey::services {

    class TilesetLoader {
    public:

        struct TileData {
            int x;
            int y;
            int id;
            bool walkable = false;
            std::string name;

            bool operator==(const TileData &other) const {
                return x == other.x &&
                       y == other.y &&
                       id == other.id &&
                       walkable == other.walkable &&
                       name == other.name;
            }

            NLOHMANN_DEFINE_TYPE_INTRUSIVE_WITH_DEFAULT(TileData, x, y, id, walkable, name)
        };

        class TilesetData {
        public:
            std::string spritesheet;
            int tilesize;
            std::string baseColorHex;
            std::vector<TileData> tiles;
            
            [[nodiscard]] std::optional<TileData> getTile(int id) const;

            [[nodiscard]] std::optional<TileData> getTile(const std::string &name) const;

            NLOHMANN_DEFINE_TYPE_INTRUSIVE(TilesetData, spritesheet, tilesize, baseColorHex, tiles)
        };

        explicit TilesetLoader(const std::string &baseAssetPath);

        [[nodiscard]] std::shared_ptr<TilesetData> load(const std::string &path) const;

    private:
        const std::string baseAssetPath;
    };
}
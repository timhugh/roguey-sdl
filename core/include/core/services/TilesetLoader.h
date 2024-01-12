#pragma once

#include <string>
#include <map>
#include <nlohmann/json.hpp>

namespace roguey::services {

    class TilesetLoader {
    public:

        struct Tile {
            int x;
            int y;
            int id;
            bool walkable = false;
            std::string name;

            bool operator==(const Tile &other) const {
                return x == other.x &&
                       y == other.y &&
                       id == other.id &&
                       walkable == other.walkable &&
                       name == other.name;
            }

            NLOHMANN_DEFINE_TYPE_INTRUSIVE_WITH_DEFAULT(Tile, x, y, id, walkable, name)
        };

        class Tileset {
            std::string spritesheet;
            int tilesize;
            std::vector<Tile> tiles;

        public:
            [[nodiscard]] std::string getSpritesheet() const;

            [[nodiscard]] int getTilesize() const;

            [[nodiscard]] std::vector<Tile> getTiles() const;

            [[nodiscard]] std::optional<Tile> getTile(int id) const;

            [[nodiscard]] std::optional<Tile> getTile(const std::string &name) const;

            NLOHMANN_DEFINE_TYPE_INTRUSIVE(Tileset, spritesheet, tilesize, tiles)
        };

        explicit TilesetLoader(const std::string &baseAssetPath);

        [[nodiscard]] std::unique_ptr<Tileset> load(const std::string &path) const;

    private:
        const std::string baseAssetPath;
    };
}
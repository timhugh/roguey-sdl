#pragma once

#include <string>
#include <map>
#include <nlohmann/json.hpp>

namespace roguey::services {

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

        bool operator==(const Tileset &other) const {
            return spritesheet == other.spritesheet &&
                   tilesize == other.tilesize &&
                   tiles == other.tiles;
        }

    public:
        std::string getSpritesheet() const;

        int getTilesize() const;

        std::vector<Tile> getTiles() const;

        std::optional<Tile> getTile(const int id) const;

        std::optional<Tile> getTile(const std::string &name) const;

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(Tileset, spritesheet, tilesize, tiles)
    };

    class TilesetLoader {
    public:
        explicit TilesetLoader(std::string baseAssetPath);

        Tileset
        load(std::string path);

    private:
        std::string baseAssetPath;
    };
}
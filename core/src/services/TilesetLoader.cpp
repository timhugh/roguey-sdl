#include "core/services/TilesetLoader.h"

#include <fstream>
#include <nlohmann/json.hpp>
#include <iostream>

using json = nlohmann::json;
using roguey::services::TilesetLoader;

TilesetLoader::TilesetLoader(const std::string &baseAssetPath) : baseAssetPath(baseAssetPath) {}

std::unique_ptr<TilesetLoader::Tileset> roguey::services::TilesetLoader::load(const std::string &path) const {
    const auto fullPath = baseAssetPath + path;
    std::ifstream f(fullPath);
    json data = json::parse(f);
    return std::make_unique<TilesetLoader::Tileset>(data.template get<Tileset>());
}

std::string TilesetLoader::Tileset::getSpritesheet() const {
    return spritesheet;
}

int TilesetLoader::Tileset::getTilesize() const {
    return tilesize;
}

std::vector<TilesetLoader::Tile> TilesetLoader::Tileset::getTiles() const {
    return tiles;
}

std::optional<TilesetLoader::Tile>
roguey::services::TilesetLoader::Tileset::getTile(const int id) const {
    for (const auto &tile: tiles) {
        if (tile.id == id) {
            return tile;
        }
    }
    return std::nullopt;
}

std::optional<TilesetLoader::Tile>
TilesetLoader::Tileset::getTile(const std::string &name) const {
    for (const auto &tile: tiles) {
        if (tile.name == name) {
            return tile;
        }
    }
    return std::nullopt;
}

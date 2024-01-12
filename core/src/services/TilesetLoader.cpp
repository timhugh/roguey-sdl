#include "core/services/TilesetLoader.h"

#include <fstream>
#include <nlohmann/json.hpp>
#include <iostream>

using json = nlohmann::json;

roguey::services::TilesetLoader::TilesetLoader(std::string baseAssetPath) {
    this->baseAssetPath = baseAssetPath;
}

roguey::services::Tileset roguey::services::TilesetLoader::load(std::string path) const {
    auto fullPath = baseAssetPath + path;
    std::ifstream f(fullPath);
    json data = json::parse(f);
    return data.template get<Tileset>();
}

std::string roguey::services::Tileset::getSpritesheet() const {
    return spritesheet;
}

int roguey::services::Tileset::getTilesize() const {
    return tilesize;
}

std::vector<roguey::services::Tile> roguey::services::Tileset::getTiles() const {
    return tiles;
}

std::optional<roguey::services::Tile> roguey::services::Tileset::getTile(const int id) const {
    for (const auto &tile: tiles) {
        if (tile.id == id) {
            return tile;
        }
    }
    return std::nullopt;
}

std::optional<roguey::services::Tile> roguey::services::Tileset::getTile(const std::string &name) const {
    for (const auto &tile: tiles) {
        if (tile.name == name) {
            return tile;
        }
    }
    return std::nullopt;
}

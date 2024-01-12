#include "core/services/TilesetLoader.h"

#include <fstream>
#include <nlohmann/json.hpp>
#include <iostream>

using json = nlohmann::json;
using roguey::services::TilesetLoader;

TilesetLoader::TilesetLoader(const std::string &baseAssetPath) : baseAssetPath(baseAssetPath) {}

std::shared_ptr<TilesetLoader::TilesetData> roguey::services::TilesetLoader::load(const std::string &path) const {
    const auto fullPath = baseAssetPath + path;
    std::ifstream f(fullPath);
    json data = json::parse(f);
    return std::make_shared<TilesetLoader::TilesetData>(data.template get<TilesetData>());
}

std::optional<TilesetLoader::TileData>
roguey::services::TilesetLoader::TilesetData::getTile(const int id) const {
    for (const auto &tile: tiles) {
        if (tile.id == id) {
            return tile;
        }
    }
    return std::nullopt;
}

std::optional<TilesetLoader::TileData>
TilesetLoader::TilesetData::getTile(const std::string &name) const {
    for (const auto &tile: tiles) {
        if (tile.name == name) {
            return tile;
        }
    }
    return std::nullopt;
}

#include "core/services/TilesetLoader.h"
#include <fstream>
#include <nlohmann/json.hpp>
#include <iostream>

using json = nlohmann::json;

roguey::services::TilesetLoader::TilesetLoader(std::string baseAssetPath) {
    this->baseAssetPath = baseAssetPath;
}

roguey::services::Tileset roguey::services::TilesetLoader::load(std::string path) {
    auto fullPath = baseAssetPath.append(path);
    std::ifstream f(fullPath);
    json data = json::parse(f);
    return data.template get<Tileset>();
}

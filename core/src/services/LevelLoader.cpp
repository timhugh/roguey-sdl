#include "core/services/LevelLoader.h"

#include <fstream>

using json = nlohmann::json;

roguey::services::LevelLoader::LevelLoader(std::string baseAssetPath) {
    this->baseAssetPath = baseAssetPath;
}

roguey::services::Level roguey::services::LevelLoader::load(std::string path) const {
    auto fullPath = baseAssetPath + path;
    std::ifstream f(fullPath);
    json data = json::parse(f);
    return data.template get<Level>();
}



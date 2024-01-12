#include "core/services/LevelLoader.h"

#include <fstream>
#include <iostream>

using json = nlohmann::json;
using roguey::services::LevelLoader;

LevelLoader::LevelLoader(const std::string &baseAssetPath) : baseAssetPath(baseAssetPath) {}

std::shared_ptr<LevelLoader::LevelData> LevelLoader::load(const std::string &path) const {
    const auto fullPath = baseAssetPath + path;
    std::cout << "Loading level from " << fullPath << std::endl;
    std::ifstream f(fullPath);
    json data = json::parse(f);
    return std::make_shared<LevelData>(data.get<LevelData>());
}

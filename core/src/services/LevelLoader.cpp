#include "core/services/LevelLoader.h"

#include <fstream>

using json = nlohmann::json;
using roguey::services::LevelLoader;

LevelLoader::LevelLoader(const std::string &baseAssetPath) : baseAssetPath(baseAssetPath) {}

LevelLoader::Level LevelLoader::load(const std::string &path) const {
    const auto fullPath = baseAssetPath + path;
    std::ifstream f(fullPath);
    json data = json::parse(f);
    return data.template get<Level>();
}

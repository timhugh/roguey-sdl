#pragma once

#include <vector>
#include <core/Drawable.h>
#include <core/services/LevelLoader.h>
#include <core/services/TilesetLoader.h>
#include <core/services/TextureLoader.h>
#include "Color.h"

using roguey::services::LevelLoader;
using roguey::services::TextureLoader;
using roguey::services::TilesetLoader;

namespace roguey {
    class Level {
    public:
        Level(const std::shared_ptr<LevelLoader::LevelData> &levelData,
              const std::shared_ptr<TilesetLoader::TilesetData> &tilesetData,
              const std::shared_ptr<TextureLoader> &textureLoader);


        std::vector<std::vector<Drawable>> tiles;
        std::vector<Drawable> entities;
        Color color;
    };
}
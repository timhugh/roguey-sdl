#pragma once

#include <SDL.h>
#include <string>
#include <map>
#include <memory>

namespace roguey::services {
    class TextureLoader {
    public:
        TextureLoader(const std::shared_ptr<SDL_Renderer> renderer, const std::string &baseAssetPath);

        ~TextureLoader();

        std::shared_ptr<SDL_Texture> load(const std::string &path);

    private:
        std::shared_ptr<SDL_Texture> loadFromFile(const std::string &path) const;

        const std::shared_ptr<SDL_Renderer> renderer;
        const std::string baseAssetPath;
        std::map<const std::string, std::shared_ptr<SDL_Texture>> textureCache;
    };
}

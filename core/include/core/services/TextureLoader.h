#pragma once

#include <SDL.h>
#include <string>
#include <map>

namespace roguey::services {
    class TextureLoader {
    public:
        TextureLoader(SDL_Renderer *renderer, const std::string &baseAssetPath);

        ~TextureLoader();

        SDL_Texture *load(const std::string &path);

    private:
        SDL_Texture *loadFromFile(const std::string &path) const;

        SDL_Renderer *renderer;
        const std::string baseAssetPath;
        std::map<const std::string, SDL_Texture *> textureCache;
    };
}

#pragma once

#include <SDL.h>
#include <string>
#include <map>

namespace roguey::services {
    class TextureLoader {
    public:
        TextureLoader(SDL_Renderer *renderer, std::string baseAssetPath);

        ~TextureLoader();

        SDL_Texture *load(std::string path);

    private:
        SDL_Texture *loadFromFile(std::string path);

        SDL_Renderer *renderer;
        std::string baseAssetPath;
        std::map<std::string, SDL_Texture *> textureCache;
    };
}

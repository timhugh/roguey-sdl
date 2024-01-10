//
// Created by Tim Heuett on 1/10/24.
//

#ifndef ROGUEY_V4_ASSETLOADER_H
#define ROGUEY_V4_ASSETLOADER_H

#include <SDL.h>
#include <string>
#include <map>

namespace roguey::services {
    class AssetLoader {
    public:
        AssetLoader(SDL_Renderer* renderer, std::string baseAssetPath);
        ~AssetLoader();
        SDL_Texture *loadTexture(std::string path);
    private:
        SDL_Texture *loadTextureFromFile(std::string path);
        SDL_Renderer *renderer;
        std::string baseAssetPath;
        std::map<std::string, SDL_Texture*> textureCache;
    };
}


#endif //ROGUEY_V4_ASSETLOADER_H

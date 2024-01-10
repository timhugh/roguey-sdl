//
// Created by Tim Heuett on 1/10/24.
//

#include <SDL_image.h>
#include "AssetLoader.h"

roguey::services::AssetLoader::AssetLoader(SDL_Renderer *renderer, std::string baseAssetPath) {
    this->renderer = renderer;
    this->baseAssetPath = baseAssetPath;

    const int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags)) {
        throw std::runtime_error(
                "SDL_image could not initialize! SDL_image Error: " +
                std::string(IMG_GetError()));
    }
}

roguey::services::AssetLoader::~AssetLoader() {
    IMG_Quit();
}

SDL_Texture *roguey::services::AssetLoader::loadTexture(std::string path) {
    SDL_Texture* texture = IMG_LoadTexture(renderer, baseAssetPath.append(path).c_str());
    if (texture == nullptr) {
        throw std::runtime_error(
                "SDL_image could not create texture! SDL_image Error: " +
                std::string(IMG_GetError()));
    }

    return texture;
}

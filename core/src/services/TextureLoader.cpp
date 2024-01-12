#include <SDL_image.h>
#include "core/services/TextureLoader.h"
#include <iostream>

roguey::services::TextureLoader::TextureLoader(
        const std::shared_ptr<SDL_Renderer> renderer,
        const std::string &baseAssetPath) : renderer(renderer), baseAssetPath(baseAssetPath) {

    const int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags)) {
        throw std::runtime_error(
                "SDL_image could not initialize! SDL_image Error: " +
                std::string(IMG_GetError()));
    }
}

roguey::services::TextureLoader::~TextureLoader() {
    textureCache.clear();
    IMG_Quit();
}

std::shared_ptr<SDL_Texture> roguey::services::TextureLoader::load(const std::string &path) {
    std::shared_ptr<SDL_Texture> texture;

    if (textureCache.contains(path)) {
        std::cout << "Using cached texture: " << path << std::endl;
        texture = textureCache[path];
    } else {
        std::cout << "Loading texture from disk: " << path << std::endl;
        texture = loadFromFile(path);
        textureCache[path] = texture;
    }

    return texture;
}

std::shared_ptr<SDL_Texture> roguey::services::TextureLoader::loadFromFile(const std::string &path) const {
    const std::string fullPath = baseAssetPath + path;
    std::shared_ptr<SDL_Texture> texture = std::shared_ptr<SDL_Texture>(
            IMG_LoadTexture(renderer.get(), fullPath.c_str()),
            SDL_DestroyTexture
    );
    if (texture == nullptr) {
        throw std::runtime_error(
                "SDL_image could not create texture! SDL_image Error: " +
                std::string(IMG_GetError()));
    }
    return texture;
}

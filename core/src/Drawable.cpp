#include "core/Drawable.h"

roguey::Drawable::Drawable(const std::shared_ptr<SDL_Texture> &texture, const int x, const int y, SDL_Rect source)
        : texture(texture), x(x), y(y), source(source) {}

void roguey::Drawable::draw(const std::shared_ptr<SDL_Renderer> &renderer, SDL_Rect destination) const {
    SDL_Texture &textureRef = *this->texture;
    SDL_RenderCopy(renderer.get(), &textureRef, &source, &destination);
}
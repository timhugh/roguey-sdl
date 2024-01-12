#pragma once

#include <SDL.h>
#include <memory>

namespace roguey {
    class Drawable {
    public:
        Drawable(const std::shared_ptr<SDL_Texture> &texture, int x, int y, SDL_Rect source);

        void draw(const std::shared_ptr<SDL_Renderer> &renderer, SDL_Rect destination) const;

        int x;
        int y;

    private:
        const std::shared_ptr<SDL_Texture> texture;
        const SDL_Rect source;
    };
}
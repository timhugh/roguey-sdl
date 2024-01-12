#pragma once

#include <SDL.h>
#include <string>
#include <memory>

namespace roguey {
    class WindowSystem {
    public:
        WindowSystem(int screenWidth, int screenHeight, const std::string &title);

        ~WindowSystem();

        [[nodiscard]] std::shared_ptr<SDL_Renderer> createRenderer() const;

    private:
        SDL_Window *window;
    };
}

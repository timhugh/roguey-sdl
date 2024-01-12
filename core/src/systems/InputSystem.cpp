#include <SDL.h>
#include "core/systems/InputSystem.h"

void roguey::systems::InputSystem::update() {
    SDL_Event event;
    while (SDL_PollEvent(&event) != 0) {
        switch (event.type) {
            case SDL_QUIT:
                quit = true;
                return;
        }
    }
}

bool roguey::systems::InputSystem::shouldQuit() const {
    return quit;
}

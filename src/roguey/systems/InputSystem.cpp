//
// Created by Tim Heuett on 1/9/24.
//

#include <SDL.h>
#include "InputSystem.h"

void InputSystem::update() {
    SDL_Event event;
    while (SDL_PollEvent(&event) != 0) {
        switch (event.type) {
            case SDL_QUIT:
                quit = true;
                return;
        }
    }
}

bool InputSystem::shouldQuit() const {
    return quit;
}

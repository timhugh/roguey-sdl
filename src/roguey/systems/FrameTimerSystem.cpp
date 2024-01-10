//
// Created by Tim Heuett on 1/9/24.
//

#include <SDL.h>
#include "FrameTimerSystem.h"

FrameTimerSystem::FrameTimerSystem(int fps) {
    _frameDelay = 1000 / fps;
}

void FrameTimerSystem::startFrame() {
    _frameStart = SDL_GetTicks();
}

void FrameTimerSystem::endFrame() {
    _frameTime = SDL_GetTicks() - _frameStart;

    if (_frameDelay > _frameTime) {
        SDL_Delay(_frameDelay - _frameTime);
    }
}

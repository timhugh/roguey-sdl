#include <SDL.h>
#include "core/systems/FrameTimerSystem.h"

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

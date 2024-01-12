#include <SDL.h>
#include "core/systems/FrameTimerSystem.h"

FrameTimerSystem::FrameTimerSystem(const int fps) : frameDelay(1000 / fps) {}

void FrameTimerSystem::startFrame() {
    frameStart = SDL_GetTicks();
}

void FrameTimerSystem::endFrame() {
    frameTime = SDL_GetTicks() - frameStart;

    if (frameDelay > frameTime) {
        SDL_Delay(frameDelay - frameTime);
    }
}

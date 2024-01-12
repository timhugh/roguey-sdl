#include <SDL.h>
#include "core/systems/FrameTimerSystem.h"

roguey::systems::FrameTimerSystem::FrameTimerSystem(const int fps) : frameDelay(1000 / fps) {}

void roguey::systems::FrameTimerSystem::startFrame() {
    frameStart = SDL_GetTicks();
}

void roguey::systems::FrameTimerSystem::endFrame() {
    frameTime = SDL_GetTicks() - frameStart;

    if (frameDelay > frameTime) {
        SDL_Delay(frameDelay - frameTime);
    }
}

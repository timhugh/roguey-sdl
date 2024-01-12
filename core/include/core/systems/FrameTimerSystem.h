#pragma once

#include <SDL_stdinc.h>

class FrameTimerSystem {

public:
    explicit FrameTimerSystem(int fps);

    void startFrame();

    void endFrame();

private:
    const int frameDelay;

    Uint32 frameStart = 0;
    Uint32 frameTime = 0;
};

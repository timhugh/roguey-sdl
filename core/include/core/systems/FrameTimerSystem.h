#pragma once

#include <SDL_stdinc.h>

class FrameTimerSystem {

public:
    explicit FrameTimerSystem(int fps);
    void startFrame();
    void endFrame();

private:
    int _frameDelay;

    Uint32 _frameStart = 0;
    Uint32 _frameTime = 0;
};

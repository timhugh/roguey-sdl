//
// Created by Tim Heuett on 1/9/24.
//

#ifndef ROGUEY_V4_FRAMETIMERSYSTEM_H
#define ROGUEY_V4_FRAMETIMERSYSTEM_H


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


#endif //ROGUEY_V4_FRAMETIMERSYSTEM_H

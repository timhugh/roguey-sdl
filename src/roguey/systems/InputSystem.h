//
// Created by Tim Heuett on 1/9/24.
//

#ifndef ROGUEY_V4_INPUTSYSTEM_H
#define ROGUEY_V4_INPUTSYSTEM_H


class InputSystem {

public:
    void update();

    bool shouldQuit() const;
private:
    bool quit = false;
};


#endif //ROGUEY_V4_INPUTSYSTEM_H

#pragma once

class InputSystem {

public:
    void update();

    bool shouldQuit() const;

private:
    bool quit = false;
};

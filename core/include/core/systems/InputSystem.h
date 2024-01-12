#pragma once

class InputSystem {

public:
    void update();

    [[nodiscard]] bool shouldQuit() const;

private:
    bool quit = false;
};

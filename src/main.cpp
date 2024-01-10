
#include <exception>
#include <iostream>
#include "roguey/Game.h"

int main() {

    try {
        roguey::Game game;
        game.run();
    } catch (const std::exception& e) {
        std::cerr << "\nEXCEPTION: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

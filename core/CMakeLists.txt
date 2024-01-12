cmake_minimum_required(VERSION 3.27)
project(roguey)

add_library(core
        src/Game.cpp
        include/core/Game.h
        src/systems/WindowSystem.cpp
        include/core/systems/WindowSystem.h
        src/systems/RenderSystem.cpp
        include/core/systems/RenderSystem.h
        src/systems/InputSystem.cpp
        include/core/systems/InputSystem.h
        src/systems/FrameTimerSystem.cpp
        include/core/systems/FrameTimerSystem.h
        src/services/TextureLoader.cpp
        include/core/services/TextureLoader.h
        src/services/LevelLoader.cpp
        include/core/services/LevelLoader.h
        include/core/services/TilesetLoader.h
        src/services/TilesetLoader.cpp
)
target_include_directories(core PUBLIC include)

target_compile_features(core PRIVATE cxx_std_23)

# TODO: would prefer to use fetchcontent here
# but there's some issue with SDL2_image
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

include(FetchContent)
FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)
FetchContent_MakeAvailable(json)

target_link_libraries(core
        PUBLIC
        SDL2_image::SDL2_image
        SDL2::SDL2
        nlohmann_json::nlohmann_json
)

add_custom_target(assets
        COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/assets ${CMAKE_BINARY_DIR}/assets
        DEPENDS ${CMAKE_SOURCE_DIR}/assets
        COMMENT "Copying assets to build directory"
        VERBATIM
)
add_dependencies(core assets)

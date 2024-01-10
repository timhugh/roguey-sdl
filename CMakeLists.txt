cmake_minimum_required(VERSION 3.27)
project(roguey_v4)

add_executable(roguey_v4
        src/main.cpp
        src/roguey/Game.cpp
        src/roguey/Game.h
        src/roguey/systems/WindowSystem.cpp
        src/roguey/systems/WindowSystem.h
        src/roguey/systems/RenderSystem.cpp
        src/roguey/systems/RenderSystem.h
        src/roguey/systems/InputSystem.cpp
        src/roguey/systems/InputSystem.h
        src/roguey/systems/FrameTimerSystem.cpp
        src/roguey/systems/FrameTimerSystem.h
)

target_compile_features(roguey_v4 PRIVATE cxx_std_23)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

target_link_libraries(roguey_v4 SDL2_image::SDL2_image SDL2::SDL2)

add_custom_target(assets
        COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/assets ${CMAKE_BINARY_DIR}/assets
        DEPENDS ${CMAKE_SOURCE_DIR}/assets
        COMMENT "Copying assets to build directory"
        VERBATIM
)
add_dependencies(roguey_v4 assets)

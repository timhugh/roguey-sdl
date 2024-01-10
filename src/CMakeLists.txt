cmake_minimum_required(VERSION 3.27)
project(roguey_v4)

add_executable(roguey_v4
        main.cpp
        roguey/Game.cpp
        roguey/Game.h
        roguey/systems/WindowSystem.cpp
        roguey/systems/WindowSystem.h
        roguey/systems/RenderSystem.cpp
        roguey/systems/RenderSystem.h
        roguey/systems/InputSystem.cpp
        roguey/systems/InputSystem.h
        roguey/systems/FrameTimerSystem.cpp
        roguey/systems/FrameTimerSystem.h
        roguey/services/AssetLoader.cpp
        roguey/services/AssetLoader.h
)

target_compile_features(roguey_v4 PRIVATE cxx_std_23)

# TODO: would prefer to use fetchcontent here
# but there's some issue with SDL2_image
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

target_link_libraries(roguey_v4
        PRIVATE
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
add_dependencies(roguey_v4 assets)

cmake_minimum_required(VERSION 3.27)
project(roguey)

add_executable(test
        src/TilesetLoaderTest.cpp
        src/Test.cpp
)
target_compile_features(test PRIVATE cxx_std_23)

# TODO: use fetchcontent here
find_package(Catch2 REQUIRED)

target_link_libraries(test
        PRIVATE
        core
        Catch2::Catch2WithMain
)

add_custom_target(test-assets
        COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/test/assets ${CMAKE_BINARY_DIR}/test/assets
        DEPENDS ${CMAKE_SOURCE_DIR}/test/assets
        COMMENT "Copying test assets to build directory"
        VERBATIM
)
add_dependencies(test test-assets)
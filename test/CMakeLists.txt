cmake_minimum_required(VERSION 3.27)
project(roguey)

add_executable(test
        src/LevelLoaderTest.cpp
)

# TODO: use fetchcontent here
find_package(Catch2 REQUIRED)

target_link_libraries(test
        PRIVATE
        core
        Catch2::Catch2WithMain
)

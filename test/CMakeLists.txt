cmake_minimum_required(VERSION 3.27)
project(roguey_v4)

add_executable(roguey_v4_tests
        roguey/LevelLoaderTest.cpp
)

# TODO: use fetchcontent here
find_package(Catch2 REQUIRED)

target_link_libraries(roguey_v4_tests
        PRIVATE
        Catch2::Catch2WithMain
)

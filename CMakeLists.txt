cmake_minimum_required(VERSION 3.27)
project(roguey)

include(FetchContent)

FetchContent_Declare(json
        URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)
FetchContent_MakeAvailable(json)

add_subdirectory(desktop)
add_subdirectory(core)
add_subdirectory(test)

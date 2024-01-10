cmake_minimum_required(VERSION 3.27)
project(roguey)

set(CMAKE_CXX_STANDARD 23)

add_executable(roguey_v4 main.cpp)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_IMAGE_INCLUDE_DIRS})

target_link_libraries(roguey_v4 ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})

cmake_minimum_required(VERSION 3.27)
project(roguey)

add_executable(desktop main.cpp)

target_compile_features(desktop PRIVATE cxx_std_23)

target_link_libraries(desktop PRIVATE core)

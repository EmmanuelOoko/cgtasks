cmake_minimum_required(VERSION 3.20)
project(house)

set(CMAKE_CXX_STANDARD 14)

add_executable(house main.cpp)

set(TARGET_LIB "/usr/lib/x86_64-linux-gnu/libGL.so" "/usr/lib/x86_64-linux-gnu/libGLU.so" "/usr/lib/x86_64-linux-gnu/libglut.so" )
target_link_libraries(house ${TARGET_LIB})




cmake_minimum_required(VERSION 3.29)
project(ServerOpenGLRenderer)

set(CMAKE_CXX_STANDARD 23)

add_executable(ServerOpenGLRenderer main.cpp
        assets/testTriangle.h
)

add_subdirectory(src)
add_subdirectory(libs)

target_include_directories(ServerOpenGLRenderer
        PRIVATE src
        PRIVATE assets
)

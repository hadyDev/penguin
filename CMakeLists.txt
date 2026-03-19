cmake_minimum_required(VERSION 3.16)
project(engine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenGL REQUIRED)

add_executable(engine
    src/glad.c
    src/main.cpp
    src/global/global.cpp
    src/global/glfw/glfw.cpp
)

add_subdirectory(libs/glfw-master)

target_include_directories(engine PRIVATE
    src
    libs 
    libs/glfw-master/include
)

target_link_libraries(engine PRIVATE glfw OpenGL::GL)
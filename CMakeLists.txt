cmake_minimum_required(VERSION 3.21)
project(Graphics_Engine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(glfw3 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)

# Engine library
add_library(Engine STATIC
        src/window.cpp
        src/renderer.cpp
        src/draw.cpp
        src/input.cpp
        src/textures.cpp
        src/engine.cpp
)

target_include_directories(Engine PUBLIC include)
target_link_libraries(Engine PUBLIC glfw glad::glad)

# Testing
add_executable(Test test.cpp)
target_link_libraries(Test PRIVATE Engine)

# Sample Projects
add_subdirectory(sample_projects/game_of_life)
add_subdirectory(sample_projects/falling_sand)
add_subdirectory(sample_projects/snake)

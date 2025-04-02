cmake_minimum_required(VERSION 3.28)
project(the-floor-is-lava)

set(CMAKE_CXX_STANDARD 17)

# SFML
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# tmxlite
add_subdirectory(external/tmxlite)

# Your source files
file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "include/*.hpp")

add_executable(the-floor-is-lava main.cpp)

target_include_directories(the-floor-is-lava PRIVATE include)

target_link_libraries(the-floor-is-lava
        PRIVATE
        sfml-graphics
        sfml-window
        sfml-system
        tmxlite
)
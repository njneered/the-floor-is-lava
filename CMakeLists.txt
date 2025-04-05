cmake_minimum_required(VERSION 3.28)
project(the-floor-is-lava)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x
)

FetchContent_Declare(
        tinyxml2
        GIT_REPOSITORY https://github.com/leethomason/tinyxml2.git
        GIT_TAG        master
)

FetchContent_MakeAvailable(SFML tinyxml2)

add_executable(the-floor-is-lava
        main.cpp
        AStar.cpp
        AStar.h
)

target_link_libraries(the-floor-is-lava
        sfml-system
        sfml-window
        sfml-graphics
        tinyxml2
)

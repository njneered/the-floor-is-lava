cmake_minimum_required(VERSION 3.28)
project(the-floor-is-lava)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x
)

#FetchContent_Declare(
#        tmxlite
#        GIT_REPOSITORY https://github.com/fallahn/tmxlite.git
#        GIT_TAG        3.1.0
#)
FetchContent_MakeAvailable(SFML)

add_executable(the-floor-is-lava
        main.cpp
        AStar.cpp
        AStar.h
)

target_link_libraries(the-floor-is-lava
        sfml-system
        sfml-window
        sfml-graphics
#        tmxlite
)

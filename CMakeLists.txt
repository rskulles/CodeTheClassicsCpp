cmake_minimum_required(VERSION 3.25)
project(CODE_THE_CLASSICS_CPP)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
include(FetchContent)

FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/sfml/sfml
        GIT_TAG 3.0.2
)

FetchContent_MakeAvailable(SFML)
add_subdirectory(gamelib)
add_subdirectory(boing)
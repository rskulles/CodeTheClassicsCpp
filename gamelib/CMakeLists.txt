cmake_minimum_required(VERSION 3.25)
project(GAMELIB LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED  ON)

add_library(gamelib include/GameObject.h
        src/Scene.cpp
        include/Scene.h
        include/GameEvent.h)

target_include_directories(gamelib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(gamelib PUBLIC SFML::Graphics)
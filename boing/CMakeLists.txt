cmake_minimum_required(VERSION 3.25)

add_executable(boing main.cpp
        src/Application.cpp
        src/include/Application.h
        src/Paddle.cpp
        src/include/Paddle.h
        src/Ball.cpp
        src/include/Ball.h
        src/TitleScene.cpp
        src/include/TitleScene.h
        src/GameScene.cpp
        src/include/GameScene.h
        src/BallEffect.cpp
        src/include/BallEffect.h
)
target_include_directories(boing PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/include)
target_link_libraries(boing PRIVATE SFML::Graphics SFML::Audio SFML::Window SFML::System gamelib)
cmake_minimum_required(VERSION 4.0)
project(SpaceInvaders)

set(CMAKE_CXX_STANDARD 20)

add_executable(SpaceInvaders main.cpp
        Game.cpp
        Game.h
        Entity.h
        Player.cpp
        Player.h
        Enemy.cpp
        Enemy.h
        Bullet.cpp
        Bullet.h
        TextureManager.h
        TextureManager.cpp
)

find_package(SFML COMPONENTS Network Graphics Window Audio System CONFIG REQUIRED)
target_link_libraries(SpaceInvaders PRIVATE SFML::Network SFML::Graphics SFML::Window SFML::Audio SFML::System)
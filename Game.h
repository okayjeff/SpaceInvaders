#ifndef SPACEINVADERS_GAME_H
#define SPACEINVADERS_GAME_H

#include "Entity.h"
#include <SFML/Graphics.hpp>
#include <list>

// constexpr float WINDOW_WIDTH{1920.f};
// constexpr float WINDOW_HEIGHT{1080.f};
constexpr float CAM_WIDTH{360.f};
constexpr float CAM_HEIGHT{240.f};
constexpr float WINDOW_WIDTH{CAM_WIDTH};
constexpr float WINDOW_HEIGHT{CAM_HEIGHT};

constexpr int ENEMY_PADDING{32};

class Game
{
  public:
    static int score;
    static std::vector<std::unique_ptr<Entity>> entities;
    static std::vector<std::unique_ptr<Entity>> addQueue;
    static std::vector<std::unique_ptr<Entity>> removeQueue;

    static void start();
    static void spawnPlayer();
    static void spawnEnemies();
    static void addEntity(std::unique_ptr<Entity> entity);
    static void update(sf::RenderWindow &window, float dt);
};

#endif // SPACEINVADERS_GAME_H

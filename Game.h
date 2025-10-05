#ifndef SPACEINVADERS_GAME_H
#define SPACEINVADERS_GAME_H

#include <SFML/Graphics.hpp>
#include <list>
#include "Entity.h"

constexpr float SCREEN_WIDTH{1920.f};
constexpr float SCREEN_HEIGHT{1080.f};
constexpr int ENEMY_PADDING{60};


class Game {
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

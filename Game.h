#ifndef SPACEINVADERS_GAME_H
#define SPACEINVADERS_GAME_H

#include <SFML/Graphics.hpp>
#include "Entity.h"

constexpr float SCREEN_WIDTH{1920.f};
constexpr float SCREEN_HEIGHT{1080.f};
constexpr int ENEMY_PADDING{60};


class Game {
  public:
  static int score;
  static std::vector<std::unique_ptr<Entity>> entities;

  static void start();
  static void spawnPlayer();
  static void spawnEnemies();
};


#endif // SPACEINVADERS_GAME_H

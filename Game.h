#ifndef SPACEINVADERS_GAME_H
#define SPACEINVADERS_GAME_H

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"

constexpr float SCREEN_WIDTH{1920.f};
constexpr float SCREEN_HEIGHT{1080.f};
constexpr int ENEMY_PADDING{120};


class Game {
  public:
  Game() {};

  int score{0};
  std::vector<std::unique_ptr<Entity>> entities{};

  void start() {
    entities.push_back(std::make_unique<Player>(
            sf::Vector2f({SCREEN_WIDTH / 2, SCREEN_HEIGHT - 200}),
            sf::Color::White));
  }

  void spawnEnemies() {
    for (int i = 1; i < static_cast<int>(SCREEN_WIDTH/ENEMY_PADDING); ++i) {
      sf::Vector2f pos {sf::Vector2f({static_cast<float>(ENEMY_PADDING * i), static_cast<float>(ENEMY_PADDING)})};
      entities.push_back(std::make_unique<Enemy>(pos, sf::Color::Blue));
    }
  }
};


#endif // SPACEINVADERS_GAME_H

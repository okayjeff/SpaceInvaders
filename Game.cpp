#include "Game.h"
#include "Player.h"
#include "Enemy.h"

#include <memory>

int Game::score;
std::vector<std::unique_ptr<Entity>> Game::entities;

void Game::start() {
  score = 0;
  spawnPlayer();
  spawnEnemies();
}

void Game::spawnPlayer() {
  entities.push_back(std::make_unique<Player>(
          sf::Vector2f({SCREEN_WIDTH / 2, SCREEN_HEIGHT - 100}),
          sf::Color::White));
}

void Game::spawnEnemies() {
  for (int i = 1; i < static_cast<int>(SCREEN_WIDTH/ENEMY_PADDING); ++i) {
    sf::Vector2f pos {sf::Vector2f({static_cast<float>(ENEMY_PADDING * i), static_cast<float>(ENEMY_PADDING)})};
    entities.push_back(std::make_unique<Enemy>(pos, sf::Color::Blue));
  }
}
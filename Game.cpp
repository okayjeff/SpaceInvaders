#include "Game.h"
#include "Enemy.h"
#include "Player.h"

#include <memory>

int Game::score;
std::vector<std::unique_ptr<Entity>> Game::entities;
std::vector<std::unique_ptr<Entity>> Game::addQueue;
std::vector<std::unique_ptr<Entity>> Game::removeQueue;

void Game::start()
{
    score = 0;
    spawnPlayer();
    spawnEnemies();
}

void Game::spawnPlayer()
{
    entities.push_back(
        std::make_unique<Player>(sf::Vector2f({WINDOW_WIDTH / 2, WINDOW_HEIGHT - 32}), sf::Color::White));
}

void Game::spawnEnemies()
{
    for (int i = 1; i < static_cast<int>(WINDOW_WIDTH / ENEMY_PADDING); ++i)
    {
        sf::Vector2f pos{sf::Vector2f({static_cast<float>(ENEMY_PADDING * i), static_cast<float>(ENEMY_PADDING)})};
        entities.push_back(std::make_unique<Enemy>(pos, sf::Color::Blue));
    }
}

void Game::addEntity(std::unique_ptr<Entity> entity)
{
    addQueue.push_back(std::move(entity));
}

void Game::update(sf::RenderWindow &window, float dt)
{
    addQueue.clear();

    for (auto &entity : entities)
    {
        entity->update(dt);
        entity->render(window);
    }

    for (auto &ptr : addQueue)
    {
        entities.push_back(std::move(ptr));
    }

    entities.erase(std::remove_if(entities.begin(), entities.end(), [](auto &e) { return e->markedForRemoval; }),
                   entities.end());
}
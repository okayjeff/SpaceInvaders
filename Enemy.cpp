#include "Enemy.h"
#include "TextureManager.h"

Enemy::Enemy(sf::Vector2f pos) : Entity(pos)
{
    sprite = std::make_unique<sf::Sprite>(TextureManager::getSpriteSheet());
    sprite->setTextureRect(TextureManager::getEnemyRect());
}

void Enemy::update(float dt)
{
    this->move(10.f, 0.f);
    this->move(0.f, 10.f);
    this->move(-10.f, 0.f);
    this->move(0.f, -10.f);
}

void Enemy::render(sf::RenderTexture &canvas)
{
    canvas.draw(*sprite);
}
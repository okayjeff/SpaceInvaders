#include "Enemy.h"

Enemy::Enemy(sf::Vector2f pos, sf::Color col)
    : Entity(std::make_unique<sf::RectangleShape>(sf::Vector2f({16.f, 16.f})), pos, col)
{
    shape->setOrigin({8.f, 8.f});
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
    canvas.draw(*shape);
}
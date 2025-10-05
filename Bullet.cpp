#include "Bullet.h"
#include "Game.h"

Bullet::Bullet(sf::Vector2f pos, sf::Color col)
    : Entity(std::make_unique<sf::CircleShape>(2.f), pos, col), lifetime(BULLET_LIFE) {};

void Bullet::update(float dt)
{
    lifetime -= dt;
    this->move(0, -dt * SPEED);

    if (lifetime <= 0.f)
    {
        markedForRemoval = true;
    }
}
void Bullet::render(sf::RenderWindow &window)
{
    window.draw(*shape);
}

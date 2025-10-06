#include "Bullet.h"
#include "Game.h"

Bullet::Bullet(sf::Vector2f pos) : Entity(pos), lifetime(BULLET_LIFE) {};

void Bullet::update(float dt)
{
    lifetime -= dt;
    this->move(0, -dt * SPEED);

    if (lifetime <= 0.f)
    {
        markedForRemoval = true;
    }
}
void Bullet::render(sf::RenderTexture &canvas)
{
    canvas.draw(sprite);
}

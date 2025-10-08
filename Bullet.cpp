#include "Bullet.h"
#include "Game.h"
#include "TextureManager.h"

Bullet::Bullet(sf::Vector2f pos) : Entity(pos), lifetime(BULLET_LIFE)
{
    sprite = std::make_unique<sf::Sprite>(TextureManager::getSpriteSheet());
    sprite->setTextureRect(TextureManager::getBulletRect());
};

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
    canvas.draw(*sprite);
}

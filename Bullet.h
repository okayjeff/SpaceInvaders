#ifndef SPACEINVADERS_BULLET_H
#define SPACEINVADERS_BULLET_H

#include "Entity.h"

constexpr float BULLET_LIFE = 3.0f;

class Bullet : public Entity
{
    float SPEED{500.f};
    float lifetime;

  public:
    Bullet(sf::Vector2f pos, sf::Color col);

    void update(float dt) override;
    void render(sf::RenderWindow &window) override;
};

#endif // SPACEINVADERS_BULLET_H

#ifndef SPACEINVADERS_BULLET_H
#define SPACEINVADERS_BULLET_H

#include "Entity.h"

constexpr float BULLET_LIFE = 3.0f;

class Bullet : public Entity
{
    float SPEED{500.f};
    float lifetime;

  public:
    Bullet(sf::Vector2f pos);

    void update(float dt) override;
    void render(sf::RenderTexture &canvas) override;
};

#endif // SPACEINVADERS_BULLET_H

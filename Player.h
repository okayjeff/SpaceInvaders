#ifndef SPACEINVADERS_PLAYER_H
#define SPACEINVADERS_PLAYER_H

#include "Entity.h"

constexpr float SHOOT_DELAY = 0.5f;

class Player : public Entity
{
    float shootTimer{0.f};
    float speed{250.f};

  public:
    Player(sf::Vector2f pos, sf::Color col);

    void update(float dt) override;

    void setVelocity(float x, float y);

    void render(sf::RenderTexture &canvas) override;
};

#endif // SPACEINVADERS_PLAYER_H

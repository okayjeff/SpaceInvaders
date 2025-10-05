#ifndef SPACEINVADERS_ENEMY_H
#define SPACEINVADERS_ENEMY_H

#include "Entity.h"

class Enemy : public Entity
{
  public:
    Enemy(sf::Vector2f pos, sf::Color col);

    void render(sf::RenderWindow &window) override;
    void update(float dt) override;
};

#endif // SPACEINVADERS_ENEMY_H

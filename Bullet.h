#ifndef SPACEINVADERS_BULLET_H
#define SPACEINVADERS_BULLET_H

#include "Entity.h"


class Bullet : public Entity {
public:
  Bullet(sf::Vector2f pos, sf::Color col) :
      Entity(std::make_unique<sf::CircleShape>(2.f), pos, col) {}

  void update(float dt) override;
  void render(sf::RenderWindow &window) override;
};


#endif // SPACEINVADERS_BULLET_H

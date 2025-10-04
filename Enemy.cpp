#include "Enemy.h"


void Enemy::update(float dt) {
  this->move(10.f, 0.f);
  this->move(0.f, 10.f);
  this->move(-10.f, 0.f);
  this->move(0.f, -10.f);
}

void Enemy::render(sf::RenderWindow &window) {
  window.draw(*shape);
}
#include "Bullet.h"

void Bullet::update(float dt) { this->move(0, -SPEED); }
void Bullet::render(sf::RenderWindow &window) { window.draw(*shape); }

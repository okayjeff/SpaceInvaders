#include "Player.h"
#include "Bullet.h"
#include "Game.h"

void Player::update(float dt) {
  this->setVelocity(0, 0);
  shootTimer -= dt;

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
    velocity.x = dt * -speed;
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
    velocity.x = dt * speed;
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
    velocity.y = dt * -speed;
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
    velocity.y = dt * speed;
  }

  this->move(velocity.x, velocity.y);

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) &&
      shootTimer <= 0.0f) {
    shootTimer = SHOOT_DELAY;

    sf::Vector2f pos = this->getPosition();
    Game::addEntity(std::make_unique<Bullet>(pos, sf::Color::White));
  }
}

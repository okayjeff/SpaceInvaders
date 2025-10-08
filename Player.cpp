#include "Player.h"
#include "Bullet.h"
#include "Game.h"
#include "TextureManager.h"

sf::Texture texture("/Users/jeff/Development/CLionProjects/SpaceInvaders/assets/sprites/SpaceInvaders.png");
sf::Vector2<int> SPRITE_SHEET_POS{4, 0};

Player::Player(sf::Vector2f pos) : Entity(pos)
{
    sprite = std::make_unique<sf::Sprite>(TextureManager::getSpriteSheet());
    sprite->setTextureRect(TextureManager::getPlayerRect());
    sprite->setOrigin({TILE_SIZE / 2, TILE_SIZE / 2});
    sprite->setPosition({0, 100});
}

void Player::update(float dt)
{
    this->setVelocity(0, 0);
    shootTimer -= dt;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
        velocity.x = dt * -speed;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        velocity.x = dt * speed;
    }

    this->move(velocity.x, velocity.y);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && shootTimer <= 0.0f)
    {
        shootTimer = SHOOT_DELAY;

        sf::Vector2f pos = this->getPosition();
        Game::addEntity(std::make_unique<Bullet>(pos));
    }
}

void Player::render(sf::RenderTexture &canvas)
{
    canvas.draw(*sprite);
}

void Player::setVelocity(float x, float y)
{
    velocity = {x, y};
}
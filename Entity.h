#ifndef SPACEINVADERS_ENTITY_H
#define SPACEINVADERS_ENTITY_H

#include <SFML/Graphics.hpp>

class Entity
{
    float SPEED{0.f};
    int TILE_WIDTH{16};
    sf::Vector2<int> SPRITE_SHEET_POS{0, 0};

  public:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2f velocity{0.f, 0.f};
    bool markedForRemoval{false};

    Entity(sf::Vector2f pos) : sprite(texture)
    {
    }

    virtual ~Entity() = default;

    virtual void update(float dt) = 0;
    virtual void render(sf::RenderTexture &canvas) = 0;

    sf::Vector2f getPosition() const
    {
        return sprite.getPosition();
    }

    void move(float x, float y)
    {
        sprite.move({x, y});
    }
};

#endif // SPACEINVADERS_ENTITY_H

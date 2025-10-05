#ifndef SPACEINVADERS_ENTITY_H
#define SPACEINVADERS_ENTITY_H

#include <SFML/Graphics.hpp>

class Entity
{
    float SPEED{0.f};
    int TILE_WIDTH{16};
    sf::Vector2<int> SPRITE_SHEET_POS{0, 0};

  public:
    std::unique_ptr<sf::Shape> shape;
    sf::Vector2f velocity{0.f, 0.f};
    bool markedForRemoval{false};

    Entity(std::unique_ptr<sf::Shape> shp, sf::Vector2f pos, sf::Color col) : shape(std::move(shp))
    {
        shape->setFillColor(col);
        shape->setPosition(pos);
    }

    virtual ~Entity() = default;

    virtual void update(float dt) = 0;
    virtual void render(sf::RenderWindow &window) = 0;

    sf::Vector2f getPosition() const
    {
        return shape->getPosition();
    }

    void move(float x, float y)
    {
        shape->move({x, y});
    }
};

#endif // SPACEINVADERS_ENTITY_H

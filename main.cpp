#include "Game.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({static_cast<unsigned>(WINDOW_WIDTH), static_cast<unsigned>(WINDOW_HEIGHT)}),
                            "SpaceInvaders");
    sf::Clock clock;
    window.setFramerateLimit(60);

    sf::RenderTexture gameCanvas({static_cast<unsigned>(CAM_WIDTH), static_cast<unsigned>(CAM_HEIGHT)});
    sf::Sprite gameSprite(gameCanvas.getTexture());
    gameCanvas.setSmooth(false);

    float scaleX = WINDOW_WIDTH / CAM_WIDTH;
    float scaleY = WINDOW_HEIGHT / CAM_HEIGHT;
    float scale = std::min(scaleX, scaleY);
    gameSprite.setScale(sf::Vector2f(scale, scale));

    float offsetX = (WINDOW_WIDTH - CAM_WIDTH * scale) / 2.0f;
    float offsetY = (WINDOW_HEIGHT - CAM_HEIGHT * scale) / 2.0f;
    gameSprite.setPosition(sf::Vector2f(offsetX, offsetY));

    Game::start();

    while (window.isOpen())
    {
        float deltaTime = clock.restart().asSeconds();

        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        Game::update(gameCanvas, deltaTime);

        window.clear(sf::Color::Black);
        window.draw(gameSprite);
        window.display();
    }

    return 0;
}
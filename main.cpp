#include "Game.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({static_cast<unsigned>(CAM_WIDTH), static_cast<unsigned>(CAM_HEIGHT)}),
                            "SpaceInvaders");
    sf::Clock clock;
    window.setFramerateLimit(60);

    sf::View view(sf::FloatRect({0.f, 0.f}, {CAM_WIDTH, CAM_HEIGHT}));
    window.setView(view);

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
        window.clear(sf::Color::Black);
        Game::update(window, deltaTime);
        window.display();
    }

    return 0;
}
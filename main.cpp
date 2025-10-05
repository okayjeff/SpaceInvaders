#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Game.h"


int main() {
  sf::RenderWindow window(sf::VideoMode({static_cast<unsigned>(SCREEN_WIDTH),
                                         static_cast<unsigned>(SCREEN_HEIGHT)}),
                          "SpaceInvaders");
  sf::Clock clock;
  window.setFramerateLimit(60);

  Game::start();

  while (window.isOpen()) {
    float deltaTime = clock.restart().asSeconds();

    while (const std::optional event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
        window.close();
      }
    }
    window.clear(sf::Color::Black);
    Game::update(window, deltaTime);
    window.display();
  }

  return 0;
}

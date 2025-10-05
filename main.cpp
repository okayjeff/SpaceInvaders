#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <regex>
#include "Game.h"


// void handleFire(const Player &player,
//                 std::vector<std::unique_ptr<Entity>> &entities,
//                 sf::RenderWindow &window) {
//   entities.erase(std::remove_if(entities.begin(), entities.end(),
//                                 [](const auto &bullet) {
//                                   return bullet->getPosition().y < -10.f;
//                                 }),
//                  entities.end());
//
//   static sf::Clock bulletClock;
//   if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) &&
//       bulletClock.getElapsedTime().asMilliseconds() > fireRate) {
//     entities.push_back(std::make_unique<Enemy>(player.getPosition()));
//     bulletClock.restart();
//   }
// }


// void spawnEnemies(std::vector<std::unique_ptr<Entity>> &entities) {
//   constexpr int padding{120};
//   for (int i = 1; i < static_cast<int>(screenWidth / padding); ++i) {
//     entities.push_back(std::make_unique<Enemy>(sf::Vector2f{
//             static_cast<float>(padding * i), static_cast<float>(padding)}));
//   }
// }


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

    for (auto &entity: Game::entities) {
      entity->update(deltaTime);
      entity->render(window);
    }

    window.display();
  }

  return 0;
}

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <regex>

const unsigned screenWidth{1920};
const unsigned screenHeight{1080};
const int speed{10};
const int bulletSpeed{15};

const float shipSize{40.f};
const int fireRate{250};
const float enemySize{30.f};

sf::Vector2f velocity{};


class Entity {
public:
  explicit Entity(const sf::Vector2f position) : position(position) {}

  sf::RectangleShape body;
  sf::Vector2f velocity;
  sf::Vector2f position;

  virtual void update() = 0;
  virtual void render(sf::RenderWindow &window) = 0;
};

class Enemy {
public:
  sf::RectangleShape body;
  sf::Vector2f velocity;

  explicit Enemy(const sf::Vector2f position) : body({enemySize, enemySize}), velocity({0.f, 0.f}) {
    this->body.setPosition(position);
    this->body.setOrigin({enemySize/2, enemySize/2});
    this->body.setFillColor(sf::Color::Blue);
  }

  sf::Vector2f getPosition() const { return this->body.getPosition(); }

  void render(sf::RenderWindow &window) const { window.draw(this->body); }

};

class Player {
public:
  sf::CircleShape body;
  sf::Vector2f velocity;

  explicit Player(const sf::Vector2f position) : body(shipSize, 3), velocity({0.f, 0.f}) {
    this->body.setPosition(position);
    this->body.setOrigin({shipSize / 2, shipSize / 2});
    this->body.setFillColor(sf::Color::White);
  };

  sf::Vector2f getPosition() const { return this->body.getPosition(); }

  void update() {
    this->resetVelocity();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
      this->velocity.x = -speed;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
      this->velocity.x = speed;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
      this->velocity.y = -speed;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
      this->velocity.y = speed;
    }

    this->body.move(this->velocity);
  }

  void resetVelocity() { this->velocity = {0.f, 0.f}; }

  void render(sf::RenderWindow &window) const { window.draw(this->body); }
};


sf::CircleShape spawnPlayer() {
  sf::CircleShape player(shipSize, 3);
  player.setFillColor(sf::Color::White);
  player.setOrigin({shipSize / 2, shipSize / 2});
  player.setPosition({static_cast<float>(screenWidth) / 2, static_cast<float>(screenHeight) - 200});
  return player;
}

void handleMovement() {
  velocity = {0.f, 0.f};

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
    velocity.x = -speed;
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
    velocity.x = speed;
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
    velocity.y = -speed;
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
    velocity.y = speed;
  }
}

sf::CircleShape spawnBullet(const sf::Vector2f &position) {
  sf::CircleShape bullet(2.f);
  bullet.setPosition(position);
  bullet.setFillColor(sf::Color::White);
  return bullet;
}

void handleFire(const Player &player, std::vector<sf::CircleShape> &bullets, sf::RenderWindow &window) {
  bullets.erase(std::remove_if(bullets.begin(), bullets.end(),
                               [](const auto &bullet) { return bullet.getPosition().y < -10.f; }),
                bullets.end());

  static sf::Clock bulletClock;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) &&
      bulletClock.getElapsedTime().asMilliseconds() > fireRate) {
    bullets.emplace_back(spawnBullet(player.getPosition()));
    bulletClock.restart();
  }

  for (auto &bullet: bullets) {
    bullet.move({0.f, -10.f});
    window.draw(bullet);
  }
}


void spawnEnemies(std::vector<Enemy>& enemies) {
  constexpr int padding {120};
  for (int i = 1; i < static_cast<int>(screenWidth/padding); ++i) {
    enemies.emplace_back(Enemy({static_cast<float>(padding * i), static_cast<float>(padding)}));
  }
}


int main() {
  sf::RenderWindow window(sf::VideoMode({screenWidth, screenHeight}), "SpaceInvaders");
  window.setFramerateLimit(60);

  // sf::CircleShape player = spawnPlayer();
  std::vector<sf::CircleShape> bullets{};
  std::vector<Enemy> enemies{};

  Player player({static_cast<float>(screenWidth) / 2, static_cast<float>(screenHeight) - 200});
  spawnEnemies(enemies);

  while (window.isOpen()) {
    while (const std::optional event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
        window.close();
      }
    }
    window.clear(sf::Color::Black);

    // handleMovement();
    handleFire(player, bullets, window);

    // render enemies
    for (auto &enemy: enemies) {
      enemy.render(window);
    }

    // player.move(velocity);
    // window.draw(player);
    player.update();
    player.render(window);

    window.display();
  }

  return 0;
}

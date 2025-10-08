#ifndef SPACEINVADERS_TEXTUREMANAGER_H
#define SPACEINVADERS_TEXTUREMANAGER_H

#include <SFML/Graphics.hpp>
#include <map>
#include <string>

class TextureManager
{
    static std::string filename;
    static std::unique_ptr<sf::Texture> spriteSheet;
    static int tileSize;
    static bool loaded;

    static void loadTexture();

  public:
    static sf::Texture &getSpriteSheet();
    static sf::IntRect getPlayerRect();
    static sf::IntRect getEnemyRect();
    static sf::IntRect getBulletRect();
};

#endif // SPACEINVADERS_TEXTUREMANAGER_H

#include "TextureManager.h"
#include <SFML/Graphics.hpp>
#include <string>

std::string TextureManager::filename{
    "/Users/jeff/Development/CLionProjects/SpaceInvaders/assets/sprites/SpaceInvaders.png"};

sf::Texture TextureManager::spriteSheet;
bool TextureManager::loaded{false};
int TextureManager::tileSize{16};

void TextureManager::loadTexture()
{
    if (!loaded)
    {
        spriteSheet.loadFromFile(filename);
        loaded = true;
    }
}

sf::Texture &TextureManager::getSpriteSheet()
{
    loadTexture();
    return spriteSheet;
}

sf::IntRect TextureManager::getPlayerRect()
{
    return sf::IntRect({4 * tileSize, 0}, {tileSize, tileSize});
}

sf::IntRect TextureManager::getEnemyRect()
{
}

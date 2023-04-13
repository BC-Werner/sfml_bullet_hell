#include "stdafx.h"
#include "AssetManager.h"

void AssetManager::LoadTexture(std::string textureName, std::string fileName)
{
    sf::Texture texture;
    if (texture.loadFromFile(fileName))
    {
        m_textures[textureName] = texture;
    }
    else
    {
        // Throw an Error
    }
}

sf::Texture& AssetManager::getTexture(std::string textureName)
{
    return m_textures.at(textureName);
}

void AssetManager::LoadFont(std::string fontName, std::string fileName)
{
    sf::Font font;
    if (font.loadFromFile(fileName))
    {
        m_fonts[fontName] = font;
    }
    else
    {
        // Throw an Error
    }
}

sf::Font& AssetManager::getFont(std::string fontName)
{
    return m_fonts.at(fontName);
}

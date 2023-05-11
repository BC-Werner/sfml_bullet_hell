#include "stdafx.h"
#include "AssetManager.h"
#include <fstream>

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

void AssetManager::LoadWaves(std::string waveName, std::string fileName)
{
    // Read from file
    std::ifstream ifs(fileName);

    if (ifs.is_open())
    {
        int direction;
        int num_enemies;
        float spawn_interval;
        float wave_end_time;

        while (ifs >> direction >> num_enemies >> spawn_interval >> wave_end_time)
        {
            // Create wave and push to map
            Wave w{ direction, num_enemies, sf::Time(sf::seconds(spawn_interval)), sf::Time(sf::seconds(wave_end_time * 60.f)) };
            m_waves[waveName].push_back(w);
        }
    }

    ifs.close();
}

std::vector<Wave>& AssetManager::getWaves(std::string waveName)
{
    return m_waves[waveName];
}

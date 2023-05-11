#pragma once
#include "Objects/Engine/Wave.h"

class AssetManager
{
public:
	AssetManager() {}
	~AssetManager() {}

	// Textures
	void LoadTexture(std::string textureName, std::string fileName);
	sf::Texture& getTexture(std::string textureName);

	// Fonts
	void LoadFont(std::string fontName, std::string fileName);
	sf::Font& getFont(std::string fontName);

	// Waves
	void LoadWaves(std::string waveName, std::string fileName);
	std::vector<Wave>& getWaves(std::string waveName);


private:
	std::map<std::string, sf::Texture> m_textures;
	std::map<std::string, sf::Font> m_fonts;
	std::map<std::string, std::vector<Wave>> m_waves;
};


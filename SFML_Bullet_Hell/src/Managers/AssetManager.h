#pragma once
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

private:
	std::map<std::string, sf::Texture> m_textures;
	std::map<std::string, sf::Font> m_fonts;
};


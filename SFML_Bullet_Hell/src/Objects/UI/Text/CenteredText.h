#pragma once
class CenteredText
{
public:
	CenteredText() {};
	CenteredText(sf::Text text, sf::Vector2f pos);

	void render(sf::RenderWindow& window);

	void setString(std::string str);

private:
	sf::Text m_text;
};


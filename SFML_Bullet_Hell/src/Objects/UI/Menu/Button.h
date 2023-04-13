#pragma once
class Button
{
public:
	Button();
	Button(sf::Text text, sf::Color color, sf::Vector2f position);
	~Button();

	void render(sf::RenderTarget& target);

private:
	sf::RectangleShape m_rect;
	sf::Text m_text;
};


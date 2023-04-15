#pragma once
#include "Objects/UI/Utility/CenteredText.h"

class Button
{
public:
	Button();
	Button(sf::Text text, sf::Color text_color, sf::Color rect_color, sf::Vector2f position);
	~Button();

	void render(sf::RenderWindow& window);

	bool contains(sf::Vector2f mouse_pos);

private:
	sf::RectangleShape m_rect;

	CenteredText m_centered_text;
};


#pragma once
#include "Objects/UI/Utility/CenteredText.h"

class Button
{
public:
	Button();
	Button(sf::Text text, sf::Color text_color, sf::Color rect_color, sf::Color hover_color, sf::Vector2f position);
	~Button();

	void render(sf::RenderWindow& window);

	void hover(bool isHovering);
	bool contains(sf::Vector2f mouse_pos);

private:
	bool hoverStatus = false;

	sf::RectangleShape m_rect;
	sf::Color m_rect_color;
	sf::Color m_hover_color;

	CenteredText m_centered_text;
};


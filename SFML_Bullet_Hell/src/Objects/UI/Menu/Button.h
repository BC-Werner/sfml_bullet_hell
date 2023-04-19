#pragma once
#include "Objects/UI/Text/CenteredText.h"
#include "Objects/GameObject.h"

class Button : public GameObject
{
public:
	Button();
	Button(sf::Text text, sf::Color text_color, sf::Color rect_color, sf::Color hover_color, sf::Vector2f position);
	~Button();

	void handleInput(sf::Event& event) override;
	void render(sf::RenderWindow& window) override;
	void update() override;

	void handleHover(sf::RenderWindow& window);
	bool contains(sf::Vector2f mouse_pos);

private:
	void _hover(bool isHovering);

private:
	bool hoverStatus = false;

	sf::RectangleShape m_rect;
	sf::Color m_rect_color;
	sf::Color m_hover_color;

	CenteredText m_centered_text;

	// Inherited via GameObject
};

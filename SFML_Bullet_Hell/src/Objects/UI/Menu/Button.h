#pragma once
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
	sf::Text m_text;
};


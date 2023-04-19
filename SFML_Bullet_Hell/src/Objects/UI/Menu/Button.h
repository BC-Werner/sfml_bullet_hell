#pragma once
#include "Objects/UI/Text/CenteredText.h"
#include "Objects/GameObject.h"

enum ButtonStatus { IDLE, HOVER, ACTIVE };

class Button : public GameObject
{
public:
	Button();
	Button(
		sf::Text text, 
		sf::Color text_color, 
		sf::Color rect_color, sf::Color hover_color, sf::Color active_color, 
		sf::Vector2f position,
		sf::RenderWindow* window
	);
	~Button();

	void handleInput(sf::Event& event) override;
	void render(sf::RenderWindow& window) override;
	void update() override;

	bool contains(sf::Vector2f mouse_pos);

private:
	sf::RenderWindow* m_window_ref;
	ButtonStatus m_status = ButtonStatus::IDLE;

	sf::RectangleShape m_rect;
	sf::Color m_idle_color;
	sf::Color m_hover_color;
	sf::Color m_active_color;

	CenteredText m_centered_text;
};

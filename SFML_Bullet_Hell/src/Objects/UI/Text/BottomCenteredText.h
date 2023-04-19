#pragma once
#include "Objects/GameObject.h"

class BottomCenteredText : public GameObject
{
public:
	BottomCenteredText() {};
	BottomCenteredText(sf::Text text, sf::Vector2f pos);

	void handleInput(sf::Event& event) override;
	void update() override;
	void render(sf::RenderWindow& window) override;

	void setString(std::string str);

private:
	sf::Text m_text;
};



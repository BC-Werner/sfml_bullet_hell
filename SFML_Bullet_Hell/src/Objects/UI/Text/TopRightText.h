#pragma once
#include "Objects/GameObject.h"

class TopRightText : public GameObject
{
public:
	TopRightText();
	TopRightText(sf::Text text, sf::Vector2f pos);

	virtual void handleInput(sf::Event& event) override;
	virtual void update(float dt) override;
	virtual void render(sf::RenderWindow& window) override;

	void setString(std::string str);

private:
	sf::Text m_text;
};


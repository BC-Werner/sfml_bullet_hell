#pragma once
#include "Objects/GameObject.h"

class CenteredText : public GameObject
{
public:
	CenteredText() {};
	CenteredText(sf::Text text, sf::Vector2f pos);

	virtual void handleInput() override;
	virtual void update() override;
	void render(sf::RenderWindow& window) override;

	void setString(std::string str);

private:
	sf::Text m_text;
};
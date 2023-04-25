#include "stdafx.h"
#include "TopRightCenteredText.h"

TopRightCenteredText::TopRightCenteredText()
{
}

TopRightCenteredText::TopRightCenteredText(sf::Text text, sf::Vector2f pos)
	: m_text(text)
{
	sf::Vector2f top_right = sf::Vector2f(m_text.getGlobalBounds().width, 0);
	sf::Vector2f localBounds = { m_text.getLocalBounds().left, m_text.getLocalBounds().top };

	m_text.setOrigin(top_right + localBounds);
	m_text.setPosition(pos);
}

void TopRightCenteredText::handleInput(sf::Event& event)
{
}

void TopRightCenteredText::update(float dt)
{
}

void TopRightCenteredText::render(sf::RenderWindow& window)
{
	window.draw(m_text);
}

void TopRightCenteredText::setString(std::string str)
{
	m_text.setString(str);
}

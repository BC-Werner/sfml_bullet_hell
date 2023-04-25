#include "stdafx.h"
#include "TopCenteredText.h"

TopCenteredText::TopCenteredText()
{
}

TopCenteredText::TopCenteredText(sf::Text text, sf::Vector2f pos)
	: m_text(text)
{
	sf::Vector2f top_center = sf::Vector2f(m_text.getGlobalBounds().width / 2.f, 0);
	sf::Vector2f localBounds = { m_text.getLocalBounds().left, m_text.getLocalBounds().top };

	m_text.setOrigin(top_center + localBounds);
	m_text.setPosition(pos);
}

void TopCenteredText::handleInput(sf::Event& event)
{
}

void TopCenteredText::update(float dt)
{
}

void TopCenteredText::render(sf::RenderWindow& window)
{
	window.draw(m_text);
}

void TopCenteredText::setString(std::string str)
{
	m_text.setString(str);
}

#include "stdafx.h"
#include "TopLeftText.h"

TopLeftText::TopLeftText()
{
}

TopLeftText::TopLeftText(sf::Text text, sf::Vector2f pos)
	: m_text(text)
{
	sf::Vector2f top_left = sf::Vector2f(0, 0);
	sf::Vector2f localBounds = { m_text.getLocalBounds().left, m_text.getLocalBounds().top };

	m_text.setOrigin(top_left + localBounds);
	m_text.setPosition(pos);
}

void TopLeftText::handleInput(sf::Event& event)
{
}

void TopLeftText::update(float dt)
{
}

void TopLeftText::render(sf::RenderWindow& window)
{
	window.draw(m_text);
}

void TopLeftText::setString(std::string str)
{
	m_text.setString(str);
}

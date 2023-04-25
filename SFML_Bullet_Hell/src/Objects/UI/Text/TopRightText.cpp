#include "stdafx.h"
#include "TopRightText.h"

TopRightText::TopRightText()
{
}

TopRightText::TopRightText(sf::Text text, sf::Vector2f pos)
	: m_text(text)
{
	sf::Vector2f top_right = sf::Vector2f(m_text.getGlobalBounds().width, 0);
	sf::Vector2f localBounds = { m_text.getLocalBounds().left, m_text.getLocalBounds().top };

	m_text.setOrigin(top_right + localBounds);
	m_text.setPosition(pos);
}

void TopRightText::handleInput(sf::Event& event)
{
}

void TopRightText::update(float dt)
{
}

void TopRightText::render(sf::RenderWindow& window)
{
	window.draw(m_text);
}

void TopRightText::setString(std::string str)
{
	m_text.setString(str);
}

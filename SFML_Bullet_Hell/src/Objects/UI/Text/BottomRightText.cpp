#include "stdafx.h"
#include "BottomRightText.h"

BottomRightText::BottomRightText()
{
}

BottomRightText::BottomRightText(sf::Text text, sf::Vector2f pos)
	: m_text(text)
{
	sf::Vector2f bottom_right = sf::Vector2f(m_text.getGlobalBounds().width, m_text.getGlobalBounds().height);
	sf::Vector2f localBounds = { m_text.getLocalBounds().left, m_text.getLocalBounds().top };

	m_text.setOrigin(bottom_right + localBounds);
	m_text.setPosition(pos);
}

void BottomRightText::handleInput(sf::Event& event)
{
}

void BottomRightText::update(float dt)
{
}

void BottomRightText::render(sf::RenderWindow& window)
{
	window.draw(m_text);
}

void BottomRightText::setString(std::string str)
{
	m_text.setString(str);
}

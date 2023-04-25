#include "stdafx.h"
#include "BottomLeftText.h"

BottomLeftText::BottomLeftText()
{
}

BottomLeftText::BottomLeftText(sf::Text text, sf::Vector2f pos)
	: m_text(text)
{
	sf::Vector2f bottom_left = sf::Vector2f(0, m_text.getGlobalBounds().height);
	sf::Vector2f localBounds = { m_text.getLocalBounds().left, m_text.getLocalBounds().top };

	m_text.setOrigin(bottom_left + localBounds);
	m_text.setPosition(pos);
}

void BottomLeftText::handleInput(sf::Event& event)
{
}

void BottomLeftText::update(float dt)
{
}

void BottomLeftText::render(sf::RenderWindow& window)
{
	window.draw(m_text);
}

void BottomLeftText::setString(std::string str)
{
	m_text.setString(str);
}

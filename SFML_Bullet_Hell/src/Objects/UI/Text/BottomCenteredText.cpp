#include "stdafx.h"
#include "BottomCenteredText.h"

BottomCenteredText::BottomCenteredText(sf::Text text, sf::Vector2f pos)
	: m_text(text)
{
	sf::Vector2f bottom_center = sf::Vector2f(m_text.getGlobalBounds().width / 2.f, m_text.getGlobalBounds().height);
	sf::Vector2f localBounds = { m_text.getLocalBounds().left, m_text.getLocalBounds().top };

	m_text.setOrigin(bottom_center + localBounds);
	m_text.setPosition(pos);
}

void BottomCenteredText::handleInput()
{
}

void BottomCenteredText::update()
{
}

void BottomCenteredText::render(sf::RenderWindow& window)
{
	window.draw(m_text);
}

void BottomCenteredText::setString(std::string str)
{
	m_text.setString(str);
}

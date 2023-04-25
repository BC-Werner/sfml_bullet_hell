#include "stdafx.h"
#include "RightCenteredText.h"

RightCenteredText::RightCenteredText()
{
}

RightCenteredText::RightCenteredText(sf::Text text, sf::Vector2f pos)
	: m_text(text)
{
	sf::Vector2f right_center = sf::Vector2f(m_text.getGlobalBounds().width, m_text.getGlobalBounds().height / 2.f);
	sf::Vector2f localBounds = { m_text.getLocalBounds().left, m_text.getLocalBounds().top };

	m_text.setOrigin(right_center + localBounds);
	m_text.setPosition(pos);
}

void RightCenteredText::handleInput(sf::Event& event)
{
}

void RightCenteredText::update(float dt)
{
}

void RightCenteredText::render(sf::RenderWindow& window)
{
	window.draw(m_text);
}

void RightCenteredText::setString(std::string str)
{
	m_text.setString(str);
}

#include "stdafx.h"
#include "LeftCenteredText.h"

LeftCenteredText::LeftCenteredText()
{
}

LeftCenteredText::LeftCenteredText(sf::Text text, sf::Vector2f pos)
	: m_text(text)
{
	sf::Vector2f left_center = sf::Vector2f(0, m_text.getGlobalBounds().height / 2.f);
	sf::Vector2f localBounds = { m_text.getLocalBounds().left, m_text.getLocalBounds().top };

	m_text.setOrigin(left_center + localBounds);
	m_text.setPosition(pos);
}

void LeftCenteredText::handleInput(sf::Event& event)
{
}

void LeftCenteredText::update(float dt)
{
}

void LeftCenteredText::render(sf::RenderWindow& window)
{
	window.draw(m_text);
}

void LeftCenteredText::setString(std::string str)
{
	m_text.setString(str);
}

#include "stdafx.h"
#include "CenteredText.h"

// Add to math utility class?
//sf::Vector2f round(const sf::Vector2f& vector)
//{
//	return sf::Vector2f(std::round(vector.x), std::round(vector.y));
//}

CenteredText::CenteredText(sf::Text text, sf::Vector2f pos)
	: m_text(text)
{
	// Center Text https://learnsfml.com/how-to-center-text/
	sf::Vector2f center = sf::Vector2f(m_text.getGlobalBounds().width / 2.f, m_text.getGlobalBounds().height / 2.f);
	sf::Vector2f localBounds = { m_text.getLocalBounds().left, m_text.getLocalBounds().top };

	m_text.setOrigin(center + localBounds);
	m_text.setPosition(pos);
}

void CenteredText::handleInput()
{
}

void CenteredText::update()
{
}

void CenteredText::render(sf::RenderWindow& window)
{
	window.draw(m_text);
}

void CenteredText::setString(std::string str)
{
	m_text.setString(str);
}

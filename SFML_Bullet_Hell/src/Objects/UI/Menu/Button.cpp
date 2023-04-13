#include "stdafx.h"
#include "Button.h"

Button::Button()
{
}

Button::Button(sf::Text text, sf::Color color, sf::Vector2f position)
{
	m_rect = sf::RectangleShape({ 200.f, 50.f });
	m_rect.setFillColor(color);
	m_rect.setPosition(position);

	m_text = text;
	m_text.setPosition(m_rect.getPosition());
}

Button::~Button()
{
}

void Button::render(sf::RenderTarget& target)
{
	target.draw(m_rect);
	target.draw(m_text);
}

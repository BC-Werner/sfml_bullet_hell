#include "stdafx.h"
#include "Button.h"

Button::Button()
{
}

Button::Button(sf::Text text, sf::Color rect_color, sf::Vector2f position)
{
	m_rect = sf::RectangleShape({ 200.f, 50.f });
	m_rect.setFillColor(rect_color);
	m_rect.setPosition(position);

	sf::FloatRect rectBounds = m_rect.getGlobalBounds();

	m_text = text;

	m_text.setOrigin({
		m_text.getGlobalBounds().width / 2,
		m_text.getGlobalBounds().height
	});

	m_text.setPosition({
		rectBounds.left + rectBounds.width / 2,
		rectBounds.top + rectBounds.height / 2
	});
}

Button::~Button()
{
}

void Button::render(sf::RenderTarget& target)
{
	target.draw(m_rect);
	target.draw(m_text);
}

bool Button::contains(sf::Vector2f mouse_pos)
{
	return m_rect.getGlobalBounds().contains(mouse_pos);
}

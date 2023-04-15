#include "stdafx.h"
#include "Button.h"

sf::Vector2f round(const sf::Vector2f& vector)
{
	return sf::Vector2f(std::round(vector.x), std::round(vector.y));
}

Button::Button()
{
}

Button::Button(sf::Text text, sf::Color text_color, sf::Color rect_color, sf::Color hover_color, sf::Vector2f position)
	: m_rect_color(rect_color), m_hover_color(hover_color)
{
	m_rect = sf::RectangleShape({ 200.f, 50.f });
	m_rect.setFillColor(rect_color);
	m_rect.setPosition(position);
	m_rect.setOrigin( round({ m_rect.getGlobalBounds().width / 2.f, m_rect.getGlobalBounds().height / 2.f }) );

	text.setFillColor(text_color);
	m_centered_text = CenteredText(text, m_rect.getPosition());
}

Button::~Button()
{
}

void Button::render(sf::RenderWindow& window)
{
	window.draw(m_rect);
	m_centered_text.render(window);
}

void Button::hover(bool isHovering)
{
	if (isHovering && !hoverStatus)
	{
		m_rect.setFillColor(m_hover_color);
		hoverStatus = true;
	}

	if (!isHovering && hoverStatus)
	{
		m_rect.setFillColor(m_rect_color);
		hoverStatus = false;
	}
}

bool Button::contains(sf::Vector2f mouse_pos)
{
	return m_rect.getGlobalBounds().contains(mouse_pos);
}

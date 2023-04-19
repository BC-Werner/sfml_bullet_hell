#include "stdafx.h"
#include "Button.h"

Button::Button()
	: m_window_ref(nullptr)
{
}

Button::Button(
	sf::Text text, 
	sf::Color text_color, 
	sf::Color rect_color, sf::Color hover_color, sf::Color active_color, 
	sf::Vector2f position,
	sf::RenderWindow* window
)
	: m_idle_color(rect_color), m_hover_color(hover_color), m_active_color(active_color), m_window_ref(window)
{
	m_rect = sf::RectangleShape({ 200.f, 50.f });
	m_rect.setFillColor(rect_color);
	m_rect.setPosition(position);
	m_rect.setOrigin( { m_rect.getGlobalBounds().width / 2.f, m_rect.getGlobalBounds().height / 2.f } );

	text.setFillColor(text_color);
	m_centered_text = CenteredText(text, m_rect.getPosition());
}

Button::~Button()
{
}

void Button::handleInput(sf::Event& event)
{
	sf::Vector2i mouse_pos = sf::Mouse::getPosition(*m_window_ref);

	m_status = IDLE;
	if (contains({(float)mouse_pos.x, (float)mouse_pos.y}))
	{
		m_status = HOVER;

		if (sf::Mouse::isButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			m_status = ACTIVE;
		}
	}

	switch (m_status)
	{
		case IDLE:
			m_rect.setFillColor(m_idle_color);
			break;
		case HOVER:
			m_rect.setFillColor(m_hover_color);
			break;
		case ACTIVE:
			m_rect.setFillColor(m_active_color);
			break;
	}
}

void Button::render(sf::RenderWindow& window)
{
	window.draw(m_rect);
	m_centered_text.render(window);
}

void Button::update()
{
}

bool Button::contains(sf::Vector2f mouse_pos)
{
	return m_rect.getGlobalBounds().contains(mouse_pos);
}

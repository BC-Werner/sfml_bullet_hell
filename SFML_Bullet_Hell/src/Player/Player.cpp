#include "stdafx.h"
#include "Player.h"

#define _USE_MATH_DEFINES
#include <math.h>

Player::Player(sf::RenderWindow& window, float speed, float size, unsigned max_health)
	: m_window(window), max_move_speed(speed), m_health(max_health), m_cirle_shape(size, 3), m_bounding_circle(size * 0.7f, 16)
{
	m_cirle_shape.setOrigin(m_cirle_shape.getRadius(), m_cirle_shape.getRadius());
	m_bounding_circle.setOrigin(m_bounding_circle.getRadius(), m_bounding_circle.getRadius());

	m_bounding_circle.setFillColor(sf::Color::Transparent);
	m_cirle_shape.setFillColor(sf::Color::Transparent);

	m_cirle_shape.setOutlineThickness(2.f);
	m_cirle_shape.setOutlineColor(sf::Color::Red);

	m_bounding_circle.setOutlineThickness(2.f);
	m_bounding_circle.setOutlineColor(sf::Color::Green);
}

void Player::handleInput(sf::Event& event)
{
	move_speed = sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) ? max_move_speed * 2.f : max_move_speed;

	move_flags.up =		sf::Keyboard::isKeyPressed(sf::Keyboard::W);
	move_flags.down =	sf::Keyboard::isKeyPressed(sf::Keyboard::S);
	move_flags.left =	sf::Keyboard::isKeyPressed(sf::Keyboard::A);
	move_flags.right =	sf::Keyboard::isKeyPressed(sf::Keyboard::D);

	// Vertical Movement
	if (move_flags.up ^ move_flags.down)
		movement_vector.y = move_flags.up ? -1.f : 1.f;
	else
		movement_vector.y = 0.f;

	// Horizontal Movement
	if (move_flags.left ^ move_flags.right)
		movement_vector.x = move_flags.left ? -1.f : 1.f;
	else
		movement_vector.x = 0.f;
}

void Player::update(float dt)
{
	sf::Vector2f dir = movement_vector;
	float Length = sqrtf(dir.x * dir.x + dir.y * dir.y);
	sf::Vector2f normalized = dir / (Length == 0.f ? 1.f : Length);
	set_position(get_position() + (normalized * move_speed * dt));

	// Rotate to look at mouse position
	sf::Vector2i mouse_pos = sf::Mouse::getPosition(m_window);
	sf::Vector2f player_pos = get_position();
	sf::Vector2f D = player_pos - sf::Vector2f(mouse_pos.x, mouse_pos.y);

	float radians = atan2f(D.y, D.x);

	m_cirle_shape.setRotation(radians * 180 / M_PI);
	m_cirle_shape.rotate(30.f);
}

void Player::render(sf::RenderWindow& window)
{
	window.draw(m_cirle_shape);
	//window.draw(m_bounding_circle);
}

void Player::set_texture(sf::Texture& texture)
{
}

void Player::set_position(sf::Vector2f position)
{
	m_cirle_shape.setPosition(position);
	m_bounding_circle.setPosition(position);
}

const sf::Vector2f Player::get_position() const
{
	return m_cirle_shape.getPosition();
}

void Player::scale(float scalar)
{
}

#include "stdafx.h"
#include "Player.h"

#define PI 3.14159265358979323846f

Player::Player(sf::RenderWindow& window)
	: m_window(window), max_move_speed(0.f), m_health(0), m_collider(0.f)
{
}

Player::Player(sf::RenderWindow& window, float speed, float size, unsigned max_health, sf::Font& font)
	:	m_window(window),
		max_move_speed(speed),
		m_health(max_health),
		m_health_text(),
		m_cirle_shape(size, 3), 
		m_collider(size * 0.7f)
{
	sf::Text _text = sf::Text("000", font, 24);
	_text.setFillColor(sf::Color::White);

	m_health_text = TopRightText(_text, {m_window.getView().getSize().x, 10.f});

	m_collider.set_position(m_cirle_shape.getPosition());

	m_cirle_shape.setOrigin(m_cirle_shape.getRadius(), m_cirle_shape.getRadius());

	m_cirle_shape.setFillColor(sf::Color::Transparent);
	m_cirle_shape.setOutlineThickness(2.f);
	m_cirle_shape.setOutlineColor(sf::Color::Red);

}

void Player::handleInput(sf::Event& event)
{
	move_speed = sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) ? max_move_speed * 2.f : max_move_speed;

	move_flags.up =		sf::Keyboard::isKeyPressed(sf::Keyboard::W);
	move_flags.down =	sf::Keyboard::isKeyPressed(sf::Keyboard::S);
	move_flags.left =	sf::Keyboard::isKeyPressed(sf::Keyboard::A);
	move_flags.right =	sf::Keyboard::isKeyPressed(sf::Keyboard::D);

	enum DirectionValues { Negative = -1, Neutral = 0, Positive = 1 };
	move_direction = { (float) Neutral, (float) Neutral };

	// Vertical Movement
	if (move_flags.up ^ move_flags.down)
		move_direction.y = move_flags.up ? (float) Negative : (float) Positive;

	// Horizontal Movement
	if (move_flags.left ^ move_flags.right)
		move_direction.x = move_flags.left ? (float) Negative : (float) Positive;

	// Debug Take Damage
	if (event.type == event.KeyReleased && event.key.code == sf::Keyboard::P)
	{
		m_health.lose_health(10);
	}
}

void Player::update(float dt)
{
	// Movement
	sf::Vector2f dir = move_direction;
	float Length = sqrtf(move_direction.x * move_direction.x + move_direction.y * move_direction.y);
	sf::Vector2f normalized = dir / (Length == 0.f ? 1.f : Length);
	set_position(get_position() + (normalized * move_speed * dt));

	// Rotate to look at mouse position
	sf::Vector2f mouse_pos = { (float)sf::Mouse::getPosition(m_window).x, (float)sf::Mouse::getPosition(m_window).y };
	sf::Vector2f player_pos = get_position();
	sf::Vector2f D = player_pos - mouse_pos;

	float radians = atan2(D.y, D.x);

	// 30 is the magic number and i have no idea why
	m_cirle_shape.setRotation(radians * 180.f / PI + 30.f);

	// Update health text
	m_health_text.setString(std::to_string(m_health.get_health()));
}

void Player::render(sf::RenderWindow& window)
{
	window.draw(m_cirle_shape);
	m_health_text.render(window);
}

void Player::set_texture(sf::Texture& texture)
{
}

void Player::set_position(sf::Vector2f position)
{
	m_cirle_shape.setPosition(position);
	m_collider.set_position(position);
}

const sf::Vector2f Player::get_position() const
{
	return m_cirle_shape.getPosition();
}

void Player::scale(float scalar)
{
}

#include "stdafx.h"
#include "Player.h"

#define PI 3.14159265358979323846f

Player::Player(sf::RenderWindow& window, BulletManager& bullet_manager)
	:	m_window_ref(window), 
		m_health_component(0, 0.1f), 
		m_collider_component(0.f), 
		m_shooting_component(bullet_manager)
{
}

Player::Player(sf::RenderWindow& window, BulletManager& bullet_manager, float size, unsigned max_health, sf::Font& font)
	:	m_window_ref(window),
		m_health_component(max_health, 0.1f),
		m_circle_shape(size, 3),
		m_collider_component(size * 0.7f),
		m_shooting_component(bullet_manager)
{
	sf::Text _text = sf::Text("000", font, 24);
	_text.setFillColor(sf::Color::White);

	m_circle_shape.setOrigin(m_circle_shape.getRadius(), m_circle_shape.getRadius());

	m_circle_shape.setFillColor(sf::Color::Transparent);
	m_circle_shape.setOutlineThickness(2.f);
	m_circle_shape.setOutlineColor(sf::Color::Red);

	m_shooting_component.set_reload_time(0.25f);
}

void Player::handleInput(sf::Event& event)
{
	// Movement
	m_movement_component.set_flags(MoveFlags{
		sf::Keyboard::isKeyPressed(sf::Keyboard::W),
		sf::Keyboard::isKeyPressed(sf::Keyboard::A),
		sf::Keyboard::isKeyPressed(sf::Keyboard::S),
		sf::Keyboard::isKeyPressed(sf::Keyboard::D),
		sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)
	});

	// Shoot
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		sf::Vector2f mouse_pos = { (float)sf::Mouse::getPosition(m_window_ref).x, (float)sf::Mouse::getPosition(m_window_ref).y };
		m_shooting_component.Shoot({ get_position(), mouse_pos, 1000.f, 50, true });
	}
}

void Player::update(float dt)
{
	// Movement
	m_movement_component.update_position(dt);
	set_position(m_movement_component.get_position());

	// Rotate to look at mouse position
	sf::Vector2f mouse_pos = { (float)sf::Mouse::getPosition(m_window_ref).x, (float)sf::Mouse::getPosition(m_window_ref).y };
	sf::Vector2f player_pos = get_position();
	sf::Vector2f D = player_pos - mouse_pos;
	float radians = atan2(D.y, D.x);
	m_circle_shape.setRotation(radians * 180.f / PI - 90.f);
}

void Player::render(sf::RenderWindow& window)
{
	window.draw(m_circle_shape);
}

void Player::set_position(sf::Vector2f position)
{
	m_movement_component.set_position(position);

	m_circle_shape.setPosition(m_movement_component.get_position());
	m_collider_component.set_position(m_movement_component.get_position());
}

const sf::Vector2f Player::get_position() const
{
	return m_movement_component.get_position();
}

HealthComponent& Player::get_health_component()
{
	return m_health_component;
}

CircleColliderComponent& Player::get_collider_component()
{
	return m_collider_component;
}

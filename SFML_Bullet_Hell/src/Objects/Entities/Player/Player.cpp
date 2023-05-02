#include "stdafx.h"
#include "Player.h"

#define PI 3.14159265358979323846f

Player::Player(sf::RenderWindow& window, BulletManager& bullet_manager)
	:	m_window_ref(window), 
		max_move_speed(0.f), 
		m_health_component(0), 
		m_collider_component(0.f), 
		m_shooting_component(bullet_manager)
{
}

Player::Player(sf::RenderWindow& window, BulletManager& bullet_manager, float speed, float size, unsigned max_health, sf::Font& font)
	:	m_window_ref(window),
		max_move_speed(speed),
		m_health_component(max_health),
		m_cirle_shape(size, 3),
		m_collider_component(size * 0.7f),
		m_shooting_component(bullet_manager)
{
	sf::Text _text = sf::Text("000", font, 24);
	_text.setFillColor(sf::Color::White);

	m_collider_component.set_position(m_cirle_shape.getPosition());

	m_cirle_shape.setOrigin(m_cirle_shape.getRadius(), m_cirle_shape.getRadius());

	m_cirle_shape.setFillColor(sf::Color::Transparent);
	m_cirle_shape.setOutlineThickness(2.f);
	m_cirle_shape.setOutlineColor(sf::Color::Red);

	m_iFrames = sf::seconds(0.1f);

	m_shooting_component.set_reload_time(0.25f);
}

void Player::handleInput(sf::Event& event)
{
	move_speed = sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) ? max_move_speed * 2.f : max_move_speed;

	// Movement
	m_movement_component.set_flags({
		sf::Keyboard::isKeyPressed(sf::Keyboard::W),
		sf::Keyboard::isKeyPressed(sf::Keyboard::S),
		sf::Keyboard::isKeyPressed(sf::Keyboard::A),
		sf::Keyboard::isKeyPressed(sf::Keyboard::D),
		sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)
	});

	// Shoot
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		sf::Vector2f mouse_pos = { (float)sf::Mouse::getPosition(m_window_ref).x, (float)sf::Mouse::getPosition(m_window_ref).y };
		m_shooting_component.Shoot({ get_position(), mouse_pos, 1000.f, 50 });
	}
}

void Player::update(float dt)
{
	// Movement
	//float Length = sqrtf(move_direction.x * move_direction.x + move_direction.y * move_direction.y);
	//sf::Vector2f normalized = move_direction / (Length == 0.f ? 1.f : Length);
	//set_position(get_position() + (normalized * move_speed * dt));

	set_position(m_movement_component.get_position() * dt);

	// Rotate to look at mouse position
	sf::Vector2f mouse_pos = { (float)sf::Mouse::getPosition(m_window_ref).x, (float)sf::Mouse::getPosition(m_window_ref).y };
	sf::Vector2f player_pos = get_position();
	sf::Vector2f D = player_pos - mouse_pos;
	float radians = atan2(D.y, D.x);
	m_cirle_shape.setRotation(radians * 180.f / PI - 90.f);

	// Update health text
	m_health_text.setString(std::to_string(m_health_component.get_health()));
}

void Player::render(sf::RenderWindow& window)
{
	window.draw(m_cirle_shape);
	m_health_text.render(window);
}

void Player::set_position(sf::Vector2f position)
{
	m_cirle_shape.setPosition(position);
	m_collider_component.set_position(position);
}

const sf::Vector2f Player::get_position() const
{
	return m_cirle_shape.getPosition();
}

HealthComponent& Player::get_health_component()
{
	return m_health_component;
}

CircleColliderComponent& Player::get_collider_component()
{
	return m_collider_component;
}

bool Player::can_take_damage()
{
	if (m_damage_timer.getElapsedTime().asSeconds() >= m_iFrames.asSeconds())
	{
		m_damage_timer.restart();
		return true;
	}
	return false;
}

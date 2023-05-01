#include "stdafx.h"
#include "Bullet.h"

Bullet::Bullet(sf::Vector2f position, sf::Vector2f target, float speed, unsigned damage)
	:	m_shape(5.f, 16), 
		m_collider(2.f), 
		m_bullet_speed(speed), 
		m_damage(damage), 
		m_is_active(false)
{
	m_shape.setFillColor(sf::Color::White);
	m_shape.setPosition(position);
	m_collider.set_position(position);

	sf::Vector2f direction = target - position;
	m_direction = normalize_direction(direction);
	m_lifetime = sf::seconds(2.f);
	m_life_clock.restart();
}

Bullet::~Bullet()
{
}

void Bullet::handleInput(sf::Event& event)
{
}

void Bullet::update(float dt)
{
	if (m_is_active)
	{
		m_shape.setPosition(m_shape.getPosition() + m_direction * m_bullet_speed * dt);

		if (m_life_clock.getElapsedTime() >= m_lifetime)
		{
			deactivate();
		}
	}
}

void Bullet::render(sf::RenderWindow& window)
{
	if (m_is_active)
	{
		window.draw(m_shape);
	}
}

CircleColliderComponent& Bullet::get_collider_component()
{
	return m_collider;
}

const unsigned Bullet::get_damage() const
{
	return m_damage;
}

const bool Bullet::is_active() const
{
	return m_is_active;
}

void Bullet::activate()
{
	m_is_active = true;
	m_life_clock.restart();
}

void Bullet::deactivate()
{
	m_is_active = false;
}

void Bullet::reactivate(sf::Vector2f position, sf::Vector2f target, float speed, unsigned damage)
{
	m_shape.setPosition(position);
	m_collider.set_position(position);
	m_bullet_speed = speed;
	m_damage = damage;

	// Normalized direction
	sf::Vector2f direction = target - position;
	m_direction = normalize_direction(direction);

	m_is_active = true;
	m_life_clock.restart();
}

sf::Vector2f Bullet::normalize_direction(sf::Vector2f direction)
{
	float L = sqrtf(direction.x * direction.x + direction.y * direction.y);
	sf::Vector2f normalized = direction / (L == 0.f ? 1.f : L);
	return normalized;
}

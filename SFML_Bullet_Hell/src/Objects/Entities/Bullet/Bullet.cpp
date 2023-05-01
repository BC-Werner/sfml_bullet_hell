#include "stdafx.h"
#include "Bullet.h"

Bullet::Bullet(sf::Vector2f position, sf::Vector2f target, float speed)
	: m_shape(2.f, 16), m_collider(2.f)
{
	activate(position, target, speed);
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
	}
}

void Bullet::render(sf::RenderWindow& window)
{
}

const int Bullet::get_damage() const
{
	return m_damage;
}

const bool Bullet::is_active() const
{
	return m_is_active;
}

void Bullet::activate(sf::Vector2f position, sf::Vector2f target, float speed)
{
	m_shape.setPosition(position);
	m_collider.set_position(position);
	m_bullet_speed = speed;

	// Normalized direction
	sf::Vector2f direction = target - position;
	float L = sqrtf(direction.x * direction.x + direction.y * direction.y);
	sf::Vector2f normalized = direction / (L == 0.f ? 1.f : L);
	m_direction = normalized;

	m_is_active = true;
}

void Bullet::deactivate()
{
	m_is_active = false;
}

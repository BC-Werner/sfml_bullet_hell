#include "stdafx.h"
#include "Bullet.h"

Bullet::Bullet(BulletData bullet_data)
	:	m_shape(5.f, 16), 
		m_collider_component(5.f), 
		m_is_active(false),
		m_draw_debug_collider(false),
		m_bullet_data(bullet_data)
{
	m_shape.setFillColor(sf::Color::White);
	m_shape.setPosition(m_bullet_data.start_position);
	m_collider_component.set_position(m_bullet_data.start_position);

	sf::Vector2f direction = m_bullet_data.end_position - m_bullet_data.start_position;
	m_direction = normalize_direction(direction);
	m_lifetime = sf::seconds(4.f);
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
		m_shape.setPosition(m_shape.getPosition() + m_direction * m_bullet_data.speed * dt);
		m_collider_component.set_position(m_shape.getPosition());

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
		if (m_draw_debug_collider)
		{
			window.draw(m_collider_component.get_shape());
		}
	}
}

CircleColliderComponent& Bullet::get_collider_component()
{
	return m_collider_component;
}

const unsigned Bullet::get_damage() const
{
	return m_bullet_data.damage;
}

const bool Bullet::is_active() const
{
	return m_is_active;
}

const bool Bullet::is_player_bullet() const
{
	return m_bullet_data.player_bullet;
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
	m_collider_component.set_position(position);
	m_bullet_data.start_position = position;
	m_bullet_data.end_position = target;
	m_bullet_data.speed = speed;
	m_bullet_data.damage = damage;

	// Normalized direction
	sf::Vector2f direction = target - position;
	m_direction = normalize_direction(direction);

	m_is_active = true;
	m_life_clock.restart();
}

void Bullet::reactivate(BulletData data)
{
	m_bullet_data = data;

	m_shape.setPosition(m_bullet_data.start_position);
	m_collider_component.set_position(m_bullet_data.start_position);

	// Normalized direction
	sf::Vector2f direction = m_bullet_data.end_position - m_bullet_data.start_position;
	m_direction = normalize_direction(direction);

	m_is_active = true;
	m_life_clock.restart();
}

void Bullet::draw_debug_collider(bool value)
{
	m_draw_debug_collider = value;
}

sf::Vector2f Bullet::normalize_direction(sf::Vector2f direction)
{
	float L = sqrtf(direction.x * direction.x + direction.y * direction.y);
	sf::Vector2f normalized = direction / (L == 0.f ? 1.f : L);
	return normalized;
}

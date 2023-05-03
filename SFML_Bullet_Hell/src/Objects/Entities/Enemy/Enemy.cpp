#include "stdafx.h"
#include "Enemy.h"

#include "Random.h"

Enemy::Enemy(float radius, bool isActive, BulletManager& bullet_manager)
	:	m_health_component(100, 0.1f),
		m_circle_shape(radius, Random::Int(4,8)),
		m_collider_component(radius * 0.7f),
		m_shooting_component(bullet_manager),
		active(isActive),
		m_speed(125.f)
{
	m_collider_component.set_position(m_circle_shape.getPosition());

	m_circle_shape.setOrigin(m_circle_shape.getRadius(), m_circle_shape.getRadius());
	m_circle_shape.setFillColor(sf::Color::Transparent);
	m_circle_shape.setOutlineThickness(4.f);
	m_circle_shape.setOutlineColor(sf::Color(Random::Int(0,255), Random::Int(0,255), Random::Int(0,255), 255));

	m_damage = (int) m_circle_shape.getPointCount();

	m_shooting_component.set_reload_time(0.1f * m_circle_shape.getPointCount());
}

Enemy::~Enemy()
{
}

void Enemy::handleInput(sf::Event& event)
{
}

void Enemy::update(float dt)
{
	// update collider position
	m_collider_component.set_position(m_circle_shape.getPosition());
	m_shooting_component.Shoot({
		get_position(),
		m_player_position_ref,
		75.f * m_circle_shape.getPointCount(),
		(unsigned)m_circle_shape.getPointCount() * 2
	});
}

void Enemy::render(sf::RenderWindow& window)
{
	window.draw(m_circle_shape);
}

CircleColliderComponent& Enemy::get_collider_component() 
{
	return m_collider_component;
}

HealthComponent& Enemy::get_health_component()
{
	return m_health_component;
}

ShootingComponent& Enemy::get_shooting_component()
{
	return m_shooting_component;
}

const int Enemy::get_damage() const
{
	return m_damage;
}

void Enemy::set_position(sf::Vector2f position)
{
	m_circle_shape.setPosition(position);
	m_collider_component.set_position(position);
}

const sf::Vector2f Enemy::get_position() const
{
	return m_circle_shape.getPosition();
}

void Enemy::update_player_position(sf::Vector2f player_position)
{
	m_player_position_ref = player_position;
}

void Enemy::move_toward(sf::Vector2f position, float dt)
{
	// Move toward player
	sf::Vector2f dir = position - get_position();
	float Length = sqrtf(dir.x * dir.x + dir.y * dir.y);
	sf::Vector2f normalized = dir / (Length == 0.f ? 1.f : Length);

	set_position(get_position() + normalized * m_speed * dt);
}

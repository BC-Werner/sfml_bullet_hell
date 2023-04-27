#include "stdafx.h"
#include "Enemy.h"

#include "Random.h"

Enemy::Enemy()
	:	m_size(Random::Float(5.f, 50.f)), 
		m_health(100), 
		m_circle_shape(m_size, Random::Int(3,8)), 
		m_collider(m_size * 0.7f)
{
	m_collider.set_position(m_circle_shape.getPosition());
	m_collider.set_radius(m_size);

	m_circle_shape.setRadius(m_size);
	m_circle_shape.setOrigin(m_circle_shape.getRadius(), m_circle_shape.getRadius());
	m_circle_shape.setFillColor(sf::Color::Red);
	m_circle_shape.setOutlineThickness(2.f);
	m_circle_shape.setOutlineColor(sf::Color(Random::Int(0,255), Random::Int(0,255), Random::Int(0,255), 255));
}

Enemy::~Enemy()
{
}

void Enemy::handleInput(sf::Event& event)
{
}

void Enemy::update(float dt)
{
	m_collider.set_position(m_circle_shape.getPosition());
}

void Enemy::render(sf::RenderWindow& window)
{
	window.draw(m_circle_shape);
}

CircleColliderComponent& Enemy::get_collider_component() 
{
	return m_collider;
}

HealthComponent& Enemy::get_health_component()
{
	return m_health;
}

void Enemy::set_position(sf::Vector2f position)
{
	m_circle_shape.setPosition(position);
	m_collider.set_position(position);
}

const sf::Vector2f Enemy::get_position() const
{
	return m_circle_shape.getPosition();
}

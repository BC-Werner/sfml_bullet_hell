#include "stdafx.h"
#include "Enemy.h"

Enemy::Enemy()
	: m_health(100), m_bounding_circle(10.f)
{
}

Enemy::~Enemy()
{
}

void Enemy::handleInput(sf::Event& event)
{
}

void Enemy::update(float dt)
{
}

void Enemy::render(sf::RenderWindow& window)
{
}

CircleColliderComponent& Enemy::get_collider() 
{
	return m_bounding_circle;
}

HealthComponent& Enemy::get_health()
{
	return m_health;
}

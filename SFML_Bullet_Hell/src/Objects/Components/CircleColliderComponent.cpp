#include "stdafx.h"
#include "CircleColliderComponent.h"

CircleColliderComponent::CircleColliderComponent(float radius)
	: m_bounding_circle(sf::CircleShape(radius, 16))
{
	m_bounding_circle.setOrigin(get_radius(), get_radius());
	m_bounding_circle.setFillColor(sf::Color::Transparent);
	m_bounding_circle.setOutlineColor(sf::Color::Red);
	m_bounding_circle.setOutlineThickness(4.f);
}

bool CircleColliderComponent::isColliding(CircleColliderComponent other)
{
	sf::Vector2f A = get_position();
	sf::Vector2f B = other.get_position();
	sf::Vector2f D = B - A;

	float dist = sqrtf((D.x * D.x) + (D.y * D.y));
	return get_radius() + other.get_radius() >= dist;
}

void CircleColliderComponent::set_position(sf::Vector2f position)
{
	m_bounding_circle.setPosition(position);
}

const sf::Vector2f CircleColliderComponent::get_position() const
{
	return m_bounding_circle.getPosition();
}

void CircleColliderComponent::set_radius(float r)
{
	m_bounding_circle.setRadius(r);
}

const float CircleColliderComponent::get_radius() const
{
	return m_bounding_circle.getRadius();
}

sf::CircleShape& CircleColliderComponent::get_shape()
{
	return m_bounding_circle;
}

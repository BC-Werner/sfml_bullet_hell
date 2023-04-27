#include "stdafx.h"
#include "CircleColliderComponent.h"

CircleColliderComponent::CircleColliderComponent(float radius)
	: m_bounding_circle(radius, 16)
{
	m_bounding_circle.setOrigin(get_radius(), get_radius());
}

bool CircleColliderComponent::isColliding(CircleColliderComponent other)
{
	sf::Vector2f A = get_position();
	sf::Vector2f B = other.get_position();
	sf::Vector2f D = B - A;

	float dist = sqrtf((D.x * D.x) + (D.y * D.y));
	return get_radius() + other.get_radius() < dist;
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

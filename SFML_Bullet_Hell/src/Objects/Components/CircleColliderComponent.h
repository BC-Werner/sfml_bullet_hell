#pragma once
#include "Component.h"

class CircleColliderComponent : public Component
{
public:
	CircleColliderComponent(float radius);

	bool isColliding(CircleColliderComponent other);
	void set_position(sf::Vector2f position);
	const sf::Vector2f get_position() const;
	const float get_radius() const;

private:
	sf::CircleShape m_bounding_circle;
};


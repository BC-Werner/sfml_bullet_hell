#pragma once
#include "Component.h"

class CircleColliderComponent : public Component
{
public:
	CircleColliderComponent(float radius);

	bool isColliding(CircleColliderComponent other);
	void set_position(sf::Vector2f position);
	const sf::Vector2f get_position() const;
	void set_radius(float r);
	const float get_radius() const;

	// Temp
	sf::CircleShape& get_shape();

private:
	sf::CircleShape m_bounding_circle;
};


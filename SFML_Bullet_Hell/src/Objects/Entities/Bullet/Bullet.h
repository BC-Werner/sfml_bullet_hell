#pragma once
#include "Objects/GameObject.h"
#include "Objects/Components/CircleColliderComponent.h"

class Bullet : public GameObject
{
public:
	Bullet(sf::Vector2f position, sf::Vector2f target, float speed);
	~Bullet();

	virtual void handleInput(sf::Event& event) override;
	virtual void update(float dt) override;
	virtual void render(sf::RenderWindow& window) override;

	CircleColliderComponent& get_collider_component();

	const int get_damage() const;
	const bool is_active() const;

	void activate(sf::Vector2f position, sf::Vector2f target, float speed);
	void deactivate();

private:
	bool m_is_active;
	int m_damage;
	float m_bullet_speed;
	sf::Vector2f m_direction;
	sf::CircleShape m_shape;
	CircleColliderComponent m_collider;
};


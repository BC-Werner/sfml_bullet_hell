#pragma once
#include "Objects/GameObject.h"
#include "Objects/Components/HealthComponent.h"
#include "Objects/Components/CircleColliderComponent.h"

class Enemy : public GameObject
{
public:
	Enemy();
	~Enemy();

	virtual void handleInput(sf::Event& event) override;
	virtual void update(float dt) override;
	virtual void render(sf::RenderWindow& window) override;

	CircleColliderComponent& get_collider_component();
	HealthComponent& get_health_component();

	void set_position(sf::Vector2f position);
	const sf::Vector2f get_position() const;

private:
	HealthComponent m_health;
	CircleColliderComponent m_collider;

	sf::CircleShape m_circle_shape;

	float m_size;
};
typedef std::shared_ptr<Enemy> EnemyPtr;

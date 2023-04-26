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

	CircleColliderComponent& get_collider();
	HealthComponent& get_health();

private:
	HealthComponent m_health;
	CircleColliderComponent m_bounding_circle;
};


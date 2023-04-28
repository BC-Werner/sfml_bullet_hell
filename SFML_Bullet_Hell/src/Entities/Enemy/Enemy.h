#pragma once
#include "Objects/GameObject.h"
#include "Objects/Components/HealthComponent.h"
#include "Objects/Components/CircleColliderComponent.h"

class Enemy : public GameObject
{
public:
	Enemy(float radius, bool isActive);
	~Enemy();

	virtual void handleInput(sf::Event& event) override;
	virtual void update(float dt) override;
	virtual void render(sf::RenderWindow& window) override;

	CircleColliderComponent& get_collider_component();
	HealthComponent& get_health_component();

	void set_position(sf::Vector2f position);
	const sf::Vector2f get_position() const;

	void set_player_location(sf::Vector2f position);

	bool active = false;

private:
	HealthComponent m_health;
	CircleColliderComponent m_collider;
	sf::CircleShape m_circle_shape;

	sf::Vector2f m_player_location;
	float m_speed;

};
typedef std::shared_ptr<Enemy> EnemyPtr;

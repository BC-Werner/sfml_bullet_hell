#pragma once
#include "Objects/GameObject.h"
#include "Objects/Components/HealthComponent.h"
#include "Objects/Components/CircleColliderComponent.h"
#include "Objects/Components/ShootingComponent.h"
#include "Managers/BulletManager.h"

class Enemy : public GameObject
{
public:
	Enemy(float radius, bool isActive, BulletManager& bullet_manager);
	~Enemy();

	virtual void handleInput(sf::Event& event) override;
	virtual void update(float dt) override;
	virtual void render(sf::RenderWindow& window) override;

	CircleColliderComponent& get_collider_component();
	HealthComponent& get_health_component();
	ShootingComponent& get_shooting_component();

	const int get_damage() const;

	void set_position(sf::Vector2f position);
	const sf::Vector2f get_position() const;

	void update_player_position(sf::Vector2f player_position);

	void move_toward(sf::Vector2f position, float dt);

	bool active = false;

private:
	HealthComponent m_health_component;
	CircleColliderComponent m_collider_component;
	ShootingComponent m_shooting_component;
	sf::CircleShape m_circle_shape;

	sf::Vector2f m_player_position_ref;

	float m_speed;
	int m_damage;

};
using EnemyPtr = std::shared_ptr<Enemy>;

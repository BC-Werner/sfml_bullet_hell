#pragma once
#include "Objects/GameObject.h"
#include "Objects/Components/HealthComponent.h"
#include "Objects/Components/CircleColliderComponent.h"
#include "Objects/Components/ShootingComponent.h"
#include "Objects/Components/MovementComponent.h"
#include "Objects/UI/Text/TopRightText.h"

class Player : public GameObject
{
public:
	Player(sf::RenderWindow& window, BulletManager& bullet_manager);
	Player(sf::RenderWindow& window, BulletManager& bullet_manager, float speed, float size, unsigned max_health, sf::Font& font);
	~Player() {};

	virtual void handleInput(sf::Event& event) override;
	virtual void update(float dt) override;
	virtual void render(sf::RenderWindow& window) override;

	void set_position(sf::Vector2f position);
	const sf::Vector2f get_position() const;

	HealthComponent& get_health_component();
	CircleColliderComponent& get_collider_component();

	bool can_take_damage();
	 
private:
	sf::RenderWindow& m_window_ref;

	// Components
	HealthComponent m_health_component;
	CircleColliderComponent m_collider_component;
	ShootingComponent m_shooting_component;
	MovementComponent m_movement_component;

	sf::CircleShape m_cirle_shape;

	TopRightText m_health_text;

	// Move into Movement Component
	sf::Vector2f move_direction;
	const float max_move_speed;
	float move_speed = max_move_speed;

	sf::Clock m_damage_timer;
	sf::Time m_iFrames;
};


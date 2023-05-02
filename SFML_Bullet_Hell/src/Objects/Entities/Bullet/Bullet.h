#pragma once
#include "Objects/GameObject.h"
#include "Objects/Components/CircleColliderComponent.h"

struct BulletData
{
	sf::Vector2f start_position;
	sf::Vector2f end_position;
	float speed;
	unsigned damage;

};

class Bullet : public GameObject
{
public:
	Bullet(sf::Vector2f position, sf::Vector2f target, float speed, unsigned damage);
	~Bullet();

	virtual void handleInput(sf::Event& event) override;
	virtual void update(float dt) override;
	virtual void render(sf::RenderWindow& window) override;

	CircleColliderComponent& get_collider_component();

	const unsigned get_damage() const;
	const bool is_active() const;

	void activate();
	void deactivate();
	void reactivate(sf::Vector2f position, sf::Vector2f target, float speed, unsigned damage);

private:
	sf::Vector2f normalize_direction(sf::Vector2f direction);

	BulletData m_bullet_data;

	bool m_is_active;
	sf::Vector2f m_direction;
	sf::CircleShape m_shape;
	CircleColliderComponent m_collider_component;
	sf::Clock m_life_clock;
	sf::Time m_lifetime;
};
using BulletPtr = std::shared_ptr<Bullet>;


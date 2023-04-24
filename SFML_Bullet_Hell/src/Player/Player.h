#pragma once
#include "Objects/GameObject.h"
#include "Objects/Components/HealthComponent.h"

class Player : public GameObject
{
public:
	Player(sf::RenderWindow& window) : m_window(window), m_health(0) {}
	Player(sf::RenderWindow& window, float size, unsigned max_health);
	~Player() {};

	virtual void handleInput(sf::Event& event) override;
	virtual void update(float dt) override;
	virtual void render(sf::RenderWindow& window) override;

	void set_texture(sf::Texture& texture);
	void set_position(sf::Vector2f position);
	const sf::Vector2f get_position() const;
	void scale(float scalar);
	 
private:
	sf::RenderWindow& m_window;
	HealthComponent m_health;

	sf::CircleShape m_cirle_shape;
	sf::CircleShape m_bounding_circle;

	sf::Vector2f movement_vector;
	float move_speed = 100.f;

	struct MoveFlags
	{
		bool left = false;
		bool right = false;
		bool up = false;
		bool down = false;
	};

	MoveFlags move_flags;
};


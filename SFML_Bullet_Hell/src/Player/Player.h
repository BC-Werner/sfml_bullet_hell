#pragma once
#include "Objects/GameObject.h"
#include "Objects/Components/HealthComponent.h"
#include "Objects/Components/CircleColliderComponent.h"
#include "Objects/UI/Text/TopRightText.h"

class Player : public GameObject
{
public:
	Player(sf::RenderWindow& window);
	Player(sf::RenderWindow& window, float speed, float size, unsigned max_health, sf::Font& font);
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
	CircleColliderComponent m_collider;

	sf::CircleShape m_cirle_shape;

	sf::Vector2f movement_vector;
	const float max_move_speed;
	float move_speed = max_move_speed;

	struct MoveFlags
	{
		bool left = false;
		bool right = false;
		bool up = false;
		bool down = false;
	};
	MoveFlags move_flags;

	TopRightText m_health_text;
};


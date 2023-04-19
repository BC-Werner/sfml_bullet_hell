#pragma once
#include "Objects/GameObject.h"
#include "Objects/Components/HealthComponent.h"

class Player : public GameObject
{
public:
	Player() : m_health(0) {}
	Player(unsigned max_health);
	Player(unsigned max_health, sf::Texture& texture);
	~Player() {};

	virtual void handleInput(sf::Event& event) override;
	virtual void update() override;
	virtual void render(sf::RenderWindow& window) override;

	void set_texture(sf::Texture& texture);
	void set_position(sf::Vector2f position);
	void scale(float scalar);
	 
private:
	HealthComponent m_health;

	sf::RectangleShape m_shape;
	sf::Texture m_texture;
	sf::Sprite m_sprite;
};


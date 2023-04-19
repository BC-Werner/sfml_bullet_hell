#pragma once
#include "Objects/GameObject.h"
#include "Objects/Components/HealthComponent.h"

class Player : public GameObject
{
public:
	Player(unsigned max_health);
	~Player() {};

	virtual void handleInput() override;
	virtual void update() override;
	virtual void render(sf::RenderWindow& window) override;

private:
	HealthComponent m_health;

	sf::RectangleShape m_shape;
};


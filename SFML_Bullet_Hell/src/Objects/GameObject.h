#pragma once
class GameObject
{
public:
	GameObject() {};
	virtual ~GameObject() {};

	virtual void handleInput() = 0;
	virtual void update() = 0;
	virtual void render(sf::RenderWindow& window) = 0;
};


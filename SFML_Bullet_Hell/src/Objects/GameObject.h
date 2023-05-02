#pragma once

class GameObject
{
public:
	virtual ~GameObject() {};

	virtual void handleInput(sf::Event& event) = 0;
	virtual void update(float dt) = 0;
	virtual void render(sf::RenderWindow& window) = 0;

private:
};


#pragma once
#include "Objects/Components/Component.h"

class GameObject
{
public:
	virtual ~GameObject() {};

	virtual void handleInput() = 0;
	virtual void update() = 0;
	virtual void render(sf::RenderWindow& window) = 0;

	void addComponent(Component* component) { m_components.push_back(component); };

private:
	std::vector<Component*> m_components;
};


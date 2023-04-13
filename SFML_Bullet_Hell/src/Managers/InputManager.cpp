#include "stdafx.h"
#include "InputManager.h"

bool InputManager::IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow& window)
{
	return (	sf::Mouse::isButtonPressed(button) &&
				object.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y));
}

sf::Vector2i InputManager::GetMousePosition(sf::RenderWindow& window)
{
	return sf::Mouse::getPosition(window);
}

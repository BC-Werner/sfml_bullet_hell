#include "stdafx.h"
#include "InputManager.h"

bool InputManager::IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow& window)
{
	sf::Vector2f mouse_pos((float) sf::Mouse::getPosition(window).x, (float) sf::Mouse::getPosition(window).y);

	return ( sf::Mouse::isButtonPressed(button) && object.getGlobalBounds().contains(mouse_pos) );
}

sf::Vector2i InputManager::GetMousePosition(sf::RenderWindow& window)
{
	return sf::Mouse::getPosition(window);
}

#include "stdafx.h"
#include "Player.h"

Player::Player(unsigned max_health)
	: m_health(max_health)
{
}

Player::Player(unsigned max_health, sf::Texture& texture)
	: m_health(max_health), m_sprite(texture)
{
}

void Player::handleInput(sf::Event& event)
{
}

void Player::update()
{
}

void Player::render(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}

void Player::set_texture(sf::Texture& texture)
{
	m_sprite.setTexture(texture);
}

void Player::set_position(sf::Vector2f position)
{
	m_sprite.setPosition(position);
}

void Player::scale(float scalar)
{
	m_sprite.scale({ scalar, scalar });
}

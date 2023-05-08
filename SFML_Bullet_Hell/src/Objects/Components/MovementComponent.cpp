#include "stdafx.h"
#include "MovementComponent.h"

enum DirectionValues { Negative = -1, Neutral = 0, Positive = 1 };

MovementComponent::MovementComponent(float move_speed)
	: M_MAX_SPEED(move_speed), m_speed(0.f), m_flags{false, false, false, false, false}
{
}

MovementComponent::~MovementComponent()
{
}

void MovementComponent::set_flags(MoveFlags flags)
{
	m_flags = flags;
}

sf::Vector2f MovementComponent::get_position() const
{
	return m_position;
}

void MovementComponent::set_position(sf::Vector2f position)
{
	m_position = position;
}

void MovementComponent::update_position(float dt)
{
	m_speed = m_flags.boost ? M_MAX_SPEED * 2.f : M_MAX_SPEED;

	m_direction = { (float) DirectionValues::Neutral, (float) DirectionValues::Neutral };

	// Vertical Movement
	if (m_flags.up ^ m_flags.down)
		m_direction.y = m_flags.up ? (float) DirectionValues::Negative : (float) DirectionValues::Positive;

	// Horizontal Movement
	if (m_flags.left ^ m_flags.right)
		m_direction.x = m_flags.left ? (float) DirectionValues::Negative : (float) DirectionValues::Positive;

	// Normalize and mult by speed
	float Length = sqrtf(m_direction.x * m_direction.x + m_direction.y * m_direction.y);
	m_direction = m_direction / (Length == 0.f ? 1.f : Length);
	m_direction *= m_speed * dt;

	m_position += m_direction;
}

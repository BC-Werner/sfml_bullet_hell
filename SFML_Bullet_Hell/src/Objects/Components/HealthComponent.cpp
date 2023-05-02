#include "stdafx.h"
#include "HealthComponent.h"

HealthComponent::HealthComponent(unsigned max_health, float invincibility_time)
	: m_max_health(max_health), m_current_health(max_health), m_invincibility_time(sf::seconds(invincibility_time))
{
}

void HealthComponent::lose_health(unsigned health)
{
	m_current_health -= health;

	if (m_current_health < 0) m_current_health = 0;
}

void HealthComponent::gain_health(unsigned health)
{
	m_current_health += health;

	if (m_current_health > m_max_health) m_current_health = m_max_health;
}

int HealthComponent::get_health() const
{
	return m_current_health;
}

void HealthComponent::set_health(unsigned health)
{
	m_current_health = health > m_max_health ? m_max_health : health;
}

int HealthComponent::get_max_health() const
{
	return m_max_health;
}

void HealthComponent::set_max_health(unsigned max_health)
{
	m_max_health = max_health;
}

bool HealthComponent::can_take_damage()
{
	if (m_time_since_last_damage_taken.getElapsedTime() >= m_invincibility_time)
	{
		m_time_since_last_damage_taken.restart();
		return true;
	}
	return false;
}

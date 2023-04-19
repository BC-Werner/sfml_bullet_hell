#include "stdafx.h"
#include "HealthComponent.h"

HealthComponent::HealthComponent(unsigned max_health)
	: m_max_health(max_health), m_current_health(max_health)
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

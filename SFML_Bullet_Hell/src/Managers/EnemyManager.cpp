#include "stdafx.h"
#include "EnemyManager.h"

EnemyManager::EnemyManager()
{
}

EnemyManager::~EnemyManager()
{
}

void EnemyManager::update(float dt)
{
	for (EnemyPtr enemy : m_enemies)
	{
		if (enemy->active)
		{
			enemy->move_toward(m_player_position, dt);
			enemy->shoot_toward(m_player_position);
			enemy->update(dt);

			if (enemy->get_health_component().get_health() <= 0)
			{
				enemy->active = false;
			}
		}
	}
}

void EnemyManager::render(sf::RenderWindow& window)
{
	for (EnemyPtr enemy : m_enemies)
	{
		if (enemy->active)
		{
			enemy->render(window);
		}
	}
}

void EnemyManager::update_player_position(sf::Vector2f position)
{
	m_player_position = position;
}

std::vector<EnemyPtr>& EnemyManager::get_enemies()
{
	return m_enemies;
}

#include "stdafx.h"
#include "WaveManager.h"
#include "Random.h"

WaveManager::WaveManager(SpawnerPtr spawner)
	: m_spawner(spawner), m_current_wave(0)
{
}

WaveManager::~WaveManager()
{
}

void WaveManager::load_waves()
{
	// Debug
	m_waves.push_back({ ScreenDirection::ScreenAny, 3, sf::Time(sf::seconds(3.5f)), sf::Time(sf::seconds(0.5f * 60)) });
	m_waves.push_back({ ScreenDirection::ScreenBottom, 8, sf::Time(sf::seconds(4.5f)), sf::Time(sf::seconds(1.0f * 60)) });
	m_waves.push_back({ ScreenDirection::ScreenLeft, 10, sf::Time(sf::seconds(3.5f)), sf::Time(sf::seconds(1.5f * 60)) });
}

void WaveManager::update(sf::Time game_time)
{
	if (m_current_wave >= m_waves.size())
	{
		return;
	}

	if (m_spawn_clock.getElapsedTime() >= m_waves[m_current_wave].spawn_interval)
	{
		for (int i = 0; i < m_waves[m_current_wave].enemies_per_interval; i++)
		{
			m_spawner->Spawn((ScreenDirection)m_waves[m_current_wave].direction);
		}
		m_spawn_clock.restart();
	}

	if (game_time >= m_waves[m_current_wave].wave_end_time)
	{
		m_current_wave++;
	}
}

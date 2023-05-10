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
	m_waves.push_back({ 3, sf::Time(sf::seconds(5.5f)), sf::Time(sf::seconds(0.5f * 60)) });
}

void WaveManager::update(sf::Time game_time)
{
	if (m_current_wave >= m_waves.size())
	{
		return;
	}

	if (m_spawn_clock.getElapsedTime() >= m_waves[m_current_wave].m_spawn_interval)
	{
		for (int i = 0; i < m_waves[m_current_wave].m_enemies_per_interval; i++)
		{
			int screen = Random::Int(1, 4);
			m_spawner->Spawn((ScreenDirection)screen);
			m_spawn_clock.restart();
		}
	}

	if (game_time >= m_waves[m_current_wave].m_wave_end_time)
	{
		m_current_wave++;
	}
}

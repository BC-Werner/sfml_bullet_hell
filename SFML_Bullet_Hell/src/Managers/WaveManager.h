#pragma once
#include "Objects/Engine/Wave.h"
#include "EnemySpawner.h"

class WaveManager
{
public:
	WaveManager() {};
	WaveManager(SpawnerPtr spawner);
	~WaveManager();

	void load_waves();
	void update(sf::Time game_time);

private:
	std::vector<Wave> m_waves;
	SpawnerPtr m_spawner;
	sf::Clock m_spawn_clock;
	int m_current_wave;
};


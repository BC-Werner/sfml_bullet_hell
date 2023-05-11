#pragma once
#include "Objects/Engine/Wave.h"
#include "EnemySpawner.h"
#include "Managers/AssetManager.h"

class WaveManager
{
public:
	WaveManager() {};
	WaveManager(SpawnerPtr spawner);
	~WaveManager();

	void load_waves(AssetManager& asset_manager);
	void update(sf::Time game_time);

	bool is_last_wave() const;

private:
	std::vector<Wave> m_waves;
	SpawnerPtr m_spawner;
	sf::Clock m_spawn_clock;
	int m_current_wave;
};


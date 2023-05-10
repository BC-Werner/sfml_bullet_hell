#pragma once
#include "Managers/BulletManager.h"

class ShootingComponent
{
public:
	ShootingComponent(float spawn_cooldown, BulletManager& bullet_manager);
	~ShootingComponent();

	void Shoot(BulletData data);

	void set_reload_time(float seconds);

private:
	BulletManager& m_bm_ref;

	// Flags
	bool canShoot;
	bool spawnFlag;

	// Timing
	sf::Clock m_time_since_last_shot;
	sf::Time m_shot_interval;
	sf::Clock m_time_since_spawn;
	sf::Time m_spawn_shot_cooldown;
};


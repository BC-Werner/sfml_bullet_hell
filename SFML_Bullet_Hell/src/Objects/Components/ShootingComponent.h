#pragma once
#include "Managers/BulletManager.h"

class ShootingComponent
{
public:
	ShootingComponent(BulletManager& bullet_manager);
	~ShootingComponent();

	void Shoot(BulletData data);

private:
	BulletManager& m_bm_ref;

	// Flags
	bool canShoot;

	// Timing
	sf::Clock m_time_since_last_shot;
	sf::Time m_reload_time;
};


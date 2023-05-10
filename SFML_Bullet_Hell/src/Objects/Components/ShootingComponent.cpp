#include "stdafx.h"
#include "ShootingComponent.h"

ShootingComponent::ShootingComponent(float spawn_cooldown, BulletManager& bullet_manager)
	:	canShoot(true), 
		spawnFlag(false),
		m_bm_ref(bullet_manager),
		m_shot_interval(sf::seconds(0.25f)),
		m_spawn_shot_cooldown(sf::seconds(spawn_cooldown))
{
	m_time_since_last_shot.restart();
}

ShootingComponent::~ShootingComponent()
{
}

void ShootingComponent::Shoot(BulletData data)
{
	if (!spawnFlag)
	{
		if (m_time_since_spawn.getElapsedTime() >= m_spawn_shot_cooldown)
		{
			spawnFlag = true;
		}
		return;
	}

	if (m_time_since_last_shot.getElapsedTime() >= m_shot_interval)
	{
		canShoot = true;
	}

	if (canShoot)
	{
		m_bm_ref.SpawnBullet(data);
		canShoot = false;
		m_time_since_last_shot.restart();
	}
}

void ShootingComponent::set_reload_time(float seconds)
{
	m_shot_interval = sf::seconds(seconds);
}

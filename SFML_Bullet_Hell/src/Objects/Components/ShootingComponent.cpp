#include "stdafx.h"
#include "ShootingComponent.h"

ShootingComponent::ShootingComponent(BulletManager& bullet_manager)
	:	canShoot(true), 
		m_bm_ref(bullet_manager),
		m_reload_time(sf::seconds(0.25f))
{
	m_time_since_last_shot.restart();
}

ShootingComponent::~ShootingComponent()
{
}

void ShootingComponent::Shoot(BulletData data)
{
	if (m_time_since_last_shot.getElapsedTime() >= m_reload_time)
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
	m_reload_time = sf::seconds(seconds);
}

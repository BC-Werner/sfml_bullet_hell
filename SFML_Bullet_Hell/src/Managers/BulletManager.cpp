#include "stdafx.h"
#include "BulletManager.h"

BulletManager::BulletManager()
{
}

BulletManager::~BulletManager()
{
}

void BulletManager::SpawnBullet(BulletData data)
{
	// Find an inactive bullet
	// -- Reactivate it with the new properties
	for (BulletPtr bullet : m_bullets)
	{
		if (!bullet->is_active())
		{
			bullet->reactivate(data.start_position, data.end_position, data.speed, data.damage);
			return;
		}
	}

	// Otherwise add a new bullet
	BulletPtr bullet = std::make_shared<Bullet>(data.start_position, data.end_position, data.speed, data.damage);
	bullet->activate();
	m_bullets.push_back(bullet);
}

std::vector<BulletPtr>& BulletManager::get_bullets()
{
	return m_bullets;
}

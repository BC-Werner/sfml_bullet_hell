#include "stdafx.h"
#include "BulletManager.h"

BulletManager::BulletManager()
{
}

BulletManager::~BulletManager()
{
}

void BulletManager::render(sf::RenderWindow& window)
{
	for (BulletPtr bullet : m_bullets)
	{
		if (bullet->is_active())
		{
			bullet->render(window);
		}
	}
}

void BulletManager::SpawnBullet(BulletData data)
{
	// Find an inactive bullet
	// -- Reactivate it with the new properties
	for (BulletPtr bullet : m_bullets)
	{
		if (bullet->is_active()) continue;

		bullet->reactivate(data);
		return;
	}

	// Otherwise add a new bullet
	BulletPtr bullet = std::make_shared<Bullet>(data);
	bullet->activate();
	m_bullets.push_back(bullet);
}

std::vector<BulletPtr>& BulletManager::get_bullets()
{
	return m_bullets;
}

void BulletManager::clean()
{
	for (auto it = m_bullets.begin(); it != m_bullets.end(); )
	{
		if (!(*it)->is_active())
		{
			it = m_bullets.erase(it);
		}
		else
		{
			it++;
		}
	}
}

void BulletManager::clear()
{
	m_bullets.clear();
}

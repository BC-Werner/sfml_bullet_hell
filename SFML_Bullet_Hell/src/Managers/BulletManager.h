#pragma once
#include "Objects/Entities/Bullet/Bullet.h"
#include <array>

class BulletManager
{
public:
	BulletManager();
	~BulletManager();

	void SpawnBullet();

private:
	std::vector<BulletPtr> m_bullets;
};


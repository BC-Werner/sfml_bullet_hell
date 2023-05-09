#pragma once
#include "Objects/Entities/Bullet/Bullet.h"

class BulletManager
{
public:
	BulletManager();
	~BulletManager();

	void render(sf::RenderWindow& window);

	void SpawnBullet(BulletData data);

	std::vector<BulletPtr>& get_bullets();
	void clean();
	void clear();

private:
	std::vector<BulletPtr> m_bullets;
};


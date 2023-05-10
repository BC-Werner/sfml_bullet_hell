#pragma once
#include "EnemyManager.h"

enum ScreenDirection { ScreenTop = 1, ScreenRight, ScreenBottom, ScreenLeft };

class EnemySpawner
{
public:
	EnemySpawner(sf::Vector2f window_size, EnemyManager& manager, BulletManager& bullet_manager);
	~EnemySpawner();

	void Spawn(ScreenDirection direction);

private:
	EnemyManager& m_enemy_manager;
	BulletManager& m_bullet_manager;
	const sf::Vector2f m_window_size;
};



#pragma once
#include "Game.h"

enum ScreenDirection { ScreenTop = 1, ScreenRight, ScreenBottom, ScreenLeft };

class EnemySpawner
{
public:
	EnemySpawner(GameDataRef data);
	~EnemySpawner();

	void Spawn(ScreenDirection direction);

private:
	GameDataRef m_data;
};



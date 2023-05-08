#pragma once
#include "Objects/Entities/Enemy/Enemy.h"
#include <vector>

class EnemyManager
{
public:
	EnemyManager();
	~EnemyManager();

private:
	std::vector<EnemyPtr> m_enemies;

};


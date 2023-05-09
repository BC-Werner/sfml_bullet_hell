#pragma once
#include "Objects/Entities/Enemy/Enemy.h"
#include <vector>

class EnemyManager
{
public:
	EnemyManager();
	~EnemyManager();

	void update(float dt);
	void render(sf::RenderWindow& window);

	void update_player_position(sf::Vector2f position);

	std::vector<EnemyPtr>& get_enemies();
	void add_enemy(EnemyPtr enemy);
	void clean();
	void clear();

private:
	std::vector<EnemyPtr> m_enemies;

	sf::Vector2f m_player_position;

};


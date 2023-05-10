#include "stdafx.h"
#include "EnemySpawner.h"
#include "Random.h"

EnemySpawner::EnemySpawner(sf::Vector2f window_size, EnemyManager& manager, BulletManager& bullet_manager)
	: m_window_size(window_size), m_enemy_manager(manager), m_bullet_manager(bullet_manager)
{
}

EnemySpawner::~EnemySpawner()
{
}

void EnemySpawner::Spawn(ScreenDirection direction)
{
	sf::Vector2f pos;

	switch (direction)
	{
	case ScreenTop:
		pos.x = Random::Float(0.f, m_window_size.x);
		pos.y = -100.f;
		break;
	case ScreenRight:
		pos.x = m_window_size.x + 100.f;
		pos.y = Random::Float(0.f, m_window_size.y);
		break;
	case ScreenBottom:
		pos.x = Random::Float(0.f, m_window_size.x);
		pos.y = m_window_size.y + 100.f;
		break;
	case ScreenLeft:
		pos.x = -100.f;
		pos.y = Random::Float(0.f, m_window_size.y);
		break;
	}

	EnemyPtr e = std::make_shared<Enemy>(Random::Float(10.f, 50.f), true, m_bullet_manager);
	e->set_position(pos);
	e->draw_debug_collider(false);
	m_enemy_manager.add_enemy(e);
	m_enemy_manager.clean();
}

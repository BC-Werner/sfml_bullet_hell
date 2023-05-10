#include "stdafx.h"
#include "EnemySpawner.h"

EnemySpawner::EnemySpawner(GameDataRef data)
	: m_data(data)
{
}

EnemySpawner::~EnemySpawner()
{
}

void EnemySpawner::Spawn(ScreenDirection direction)
{
	sf::Vector2f window_size = m_data->m_window.getView().getSize();
	float x, y;

	switch (direction)
	{
	case ScreenTop:
		x = Random::Float(0.f, window_size.x);
		y = -100.f;
		break;
	case ScreenRight:
		x = window_size.x + 100.f;
		y = Random::Float(0.f, window_size.y);
		break;
	case ScreenBottom:
		x = Random::Float(0.f, window_size.x);
		y = window_size.y + 100.f;
		break;
	case ScreenLeft:
		x = -100.f;
		y = Random::Float(0.f, window_size.y);
		break;
	}

	EnemyPtr e = std::make_shared<Enemy>(Random::Float(10.f, 50.f), true, m_data->bullet_manager);
	e->set_position({x,y});
	e->draw_debug_collider(false);
	m_data->enemy_manager.add_enemy(e);
	m_data->enemy_manager.clean();
}

#include "stdafx.h"
#include "GameState.h"
#include "PauseState.h"
#include "GameOverState.h"

GameState::GameState(GameDataRef data)
	:	m_data(data), 
		m_player(
			data->m_window, 
			data->bullet_manager,
			30.f, 
			100, 
			data->asset_manager.getFont("Kanit")
		),
		m_spawner(data),
		m_health_text()
{
	sf::Vector2f window_size = m_data->m_window.getView().getSize();
	sf::Font& font = m_data->asset_manager.getFont("Kanit");
	std::string health_str = std::to_string(m_player.get_health_component().get_health());
	const float PADDING = 10.f;

	m_health_text = TopRightText(
		sf::Text(health_str, font, 24),
		{ window_size.x - PADDING, PADDING }
	);

	m_game_clock_text = BottomCenteredText(
		sf::Text("00:00", font, 20), 
		{ window_size.x / 2.f, window_size.y }
	);

	m_player.set_position({ window_size.x / 2.f, window_size.y / 2.f });

	m_spawn_time = sf::seconds(1.5f);
	m_spawn_clock.restart();
}

GameState::~GameState()
{
}

void GameState::handleInput(sf::Event& event)
{
	// Keyboard Events
	if (event.type == event.KeyReleased && event.key.code == sf::Keyboard::Escape)
	{
		Pause();
	}

	m_player.handleInput(event);
}

void GameState::update(float dt)
{
	m_game_clock_text.setString(m_game_clock.to_string());
	m_player.update(dt);

	// Spawn New Enemies
	if (m_spawn_clock.getElapsedTime() >= m_spawn_time)
	{
		int screen = Random::Int(1, 4);
		m_spawner.Spawn((ScreenDirection)screen);
		m_spawn_clock.restart();
	}

	// TODO: move collision specific logic to a collision manager
	// Update Collisions
	for (EnemyPtr enemy : m_data->enemy_manager.get_enemies())
	{
		if (!enemy->active) continue;

		// Collide with player
		if (
			m_player.get_collider_component().isColliding(enemy->get_collider_component()) && 
			m_player.get_health_component().can_take_damage()
		)
		{
			// Damage player
			m_player.get_health_component().lose_health( enemy->get_damage() );
		}

		// Collide with other enemies
		for (EnemyPtr other : m_data->enemy_manager.get_enemies())
		{
			if (other == enemy) continue;

			if (enemy->get_collider_component().isColliding(other->get_collider_component()))
			{
				// Get dist between
				sf::Vector2f A = enemy->get_position();
				sf::Vector2f B = other->get_position();
				sf::Vector2f D = B - A;
				float dist = sqrtf((D.x * D.x) + (D.y * D.y));

				// Normalize -D
				float L = sqrtf(D.x * D.x + D.y * D.y);
				sf::Vector2f normalized = -D / (L == 0.f ? 1.f : L);

				// Move away by overlap
				enemy->set_position(enemy->get_position() + normalized);
			}
		}
	}

	// Update bullet collision
	auto bullets = m_data->bullet_manager.get_bullets();
	for (BulletPtr bullet : bullets)
	{
		if (!bullet->is_active()) continue;

		bullet->update(dt);

		// Handle player bullets
		if (bullet->is_player_bullet())
		{
			for (EnemyPtr enemy : m_data->enemy_manager.get_enemies())
			{
				if (!enemy->active) continue;

				if (
					bullet->get_collider_component().isColliding(enemy->get_collider_component()) &&
					enemy->get_health_component().can_take_damage()
				)
				{
					enemy->get_health_component().lose_health(bullet->get_damage());
					bullet->deactivate();
					m_player.get_health_component().gain_health(1);
				}
			}
		}

		// Handle enemy bullets
		if (!bullet->is_player_bullet())
		{
			if (
				bullet->get_collider_component().isColliding(m_player.get_collider_component()) && 
				m_player.get_health_component().can_take_damage()
			)
			{
					m_player.get_health_component().lose_health(bullet->get_damage());
					bullet->deactivate();
			}
		}
	}

	// Update Enemies
	m_data->enemy_manager.update_player_position(m_player.get_position());
	m_data->enemy_manager.update(dt);

	 // Update helth text
	m_health_text.setString(std::to_string(m_player.get_health_component().get_health()));

	// End game
	if (m_player.get_health_component().get_health() <= 0.0f)
	{
		m_data->state_manager.AddState(StateRef(std::make_unique<GameOverState>(m_data)), true);
		return;
	}
}

void GameState::render(sf::RenderWindow& window)
{
	m_player.render(window);
	m_game_clock_text.render(window);

	m_data->enemy_manager.render(window);
	m_data->bullet_manager.render(window);

	m_health_text.render(window);
}

void GameState::Init()
{
	m_data->enemy_manager.clear();
	m_data->bullet_manager.clear();
	for (int i = 0; i < 10; i++)
	{
		int screen = Random::Int(1, 4);
		m_spawner.Spawn((ScreenDirection)screen);
	}
}

void GameState::Pause()
{
	m_game_clock.Pause();
	m_data->state_manager.AddState(StateRef(std::make_unique<PauseState>(m_data)), false);
}

void GameState::Resume()
{
	m_game_clock.Resume();
}

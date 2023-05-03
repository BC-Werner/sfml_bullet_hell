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

	m_game_clock = GameClock(
		sf::Text("00:00", font, 20), 
		sf::Color::White, 
		{ window_size.x / 2.f, window_size.y }
	);

	m_player.set_position({ window_size.x / 2.f, window_size.y / 2.f });

	for (EnemyPtr enemy : m_enemies)
	{
	}
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

	// Debug Game Over
	if (event.type == event.KeyReleased && event.key.code == sf::Keyboard::Z)
	{
		m_data->state_manager.AddState(StateRef(std::make_unique<GameOverState>(m_data)), true);
	}

	m_player.handleInput(event);

	for (EnemyPtr enemy : m_enemies)
	{
		if (enemy->active)
			enemy->handleInput(event);
	}
}

void GameState::update(float dt)
{
	m_game_clock.update(dt);
	m_player.update(dt);

	// TODO: move enmy specific logic to an enemy manager
	// TODO: move collision specific logic to a collision manager
	for (EnemyPtr enemy : m_enemies)
	{
		if (!enemy->active) continue;

		// Update targeting
		enemy->update_player_position(m_player.get_position());

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
		for (EnemyPtr other : m_enemies)
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

		enemy->move_toward(m_player.get_position(), dt);
		enemy->update(dt);

		// Deactivate enemy or update
		if (enemy->get_health_component().get_health() <= 0)
		{
			enemy->active = false;
		}
	}

	auto bullets = m_data->bullet_manager.get_bullets();
	for (BulletPtr bullet : bullets)
	{
		bullet->update(dt);

		if (
			bullet->is_active() &&
			bullet->get_collider_component().isColliding(m_player.get_collider_component()) && 
			m_player.get_health_component().can_take_damage()
		)
		{
			if (!bullet->is_player_bullet())
			{
				m_player.get_health_component().lose_health(bullet->get_damage());
				bullet->deactivate();
			}
		}
	}

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
	m_game_clock.render(window);

	for (EnemyPtr enemy : m_enemies)
	{
		if (enemy->active)
			enemy->render(window);
	}

	auto bullets = m_data->bullet_manager.get_bullets();
	for (BulletPtr bullet : bullets)
	{
		bullet->render(window);
	}

	m_health_text.render(window);
}

void GameState::Init()
{
	sf::Vector2f window_size = m_data->m_window.getView().getSize();
	for (int i = 0; i < 3; i++)
	{
		EnemyPtr e = std::make_shared<Enemy>(Random::Float(10.f, 50.f), true, m_data->bullet_manager);
		e->set_position({ Random::Float(100.f, window_size.x - 100.f), Random::Float(100.f, window_size.y - 100.f) });
		m_enemies.push_back(e);
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
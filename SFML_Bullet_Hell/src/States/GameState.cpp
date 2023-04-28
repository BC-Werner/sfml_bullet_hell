#include "stdafx.h"
#include "GameState.h"
#include "PauseState.h"
#include "GameOverState.h"

GameState::GameState(GameDataRef data)
	:	m_data(data), 
		m_player(
			m_data->m_window, 
			200.f, 
			30.f, 
			100, 
			data->asset_manager.getFont("Kanit")
		),
		m_health_text()
{
	sf::Vector2f window_size = m_data->m_window.getView().getSize();
	sf::Font& font = m_data->asset_manager.getFont("Kanit");
	std::string health_str = std::to_string(m_player.get_health_component().get_health());

	m_health_text = TopRightText(
		sf::Text(health_str, font, 24),
		{ window_size.x, 10.f }
	);

	m_game_clock = GameClock(
		sf::Text("00:00", font, 20), 
		sf::Color::White, 
		{ window_size.x / 2.f, window_size.y }
	);

	m_player.set_position({ window_size.x / 2.f, window_size.y / 2.f });
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

	for (EnemyPtr enemy : m_enemies)
	{
		if (enemy->active)
		{
			if (m_player.can_take_damage() && m_player.get_collider_component().isColliding(enemy->get_collider_component()))
			{
				m_player.get_health_component().lose_health(2.f);
				// Update helth text
				m_health_text.setString(std::to_string(m_player.get_health_component().get_health()));

				if (m_player.get_health_component().get_health() <= 0.0f)
				{
					m_data->state_manager.AddState(StateRef(std::make_unique<GameOverState>(m_data)), true);
					return;
				}

			}

			// get player location
			enemy->set_player_location(m_player.get_position());
			enemy->update(dt);
		}
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

	m_health_text.render(window);
}

void GameState::Init()
{
	sf::Vector2f window_size = m_data->m_window.getView().getSize();
	for (int i = 0; i < 3; i++)
	{
		EnemyPtr e = std::make_shared<Enemy>(Random::Float(10.f, 50.f), true);
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
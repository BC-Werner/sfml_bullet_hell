#include "stdafx.h"
#include "GameState.h"

GameState::GameState(GameDataRef data)
	: m_data(data)
{
	sf::Vector2f window_size = m_data->m_window.getView().getSize();
	sf::Font& font = m_data->asset_manager.getFont("Kanit");

	m_game_clock = GameClock(sf::Text("00:00", font, 20), sf::Color::White, { window_size.x / 2.f, window_size.y });
}

GameState::~GameState()
{
}

void GameState::handleInput(sf::Event& event)
{
	if (event.type == event.KeyReleased && event.key.code == sf::Keyboard::P)
	{
		m_game_clock.Pause();
	}
	if (event.type == event.KeyReleased && event.key.code == sf::Keyboard::R)
	{
		m_game_clock.Resume();
	}
	if (event.type == event.KeyReleased && event.key.code == sf::Keyboard::Q)
	{
		m_game_clock.Restart();
	}
}

void GameState::update()
{
	m_game_clock.update();
}

void GameState::render(sf::RenderWindow& window)
{
	m_game_clock.render(window);
}

void GameState::Init()
{
}

void GameState::Pause()
{
}

void GameState::Resume()
{
}
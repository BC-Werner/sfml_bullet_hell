#include "stdafx.h"
#include "GameState.h"

GameState::GameState(GameDataRef data)
	: m_data(data)
{
	_font = m_data->asset_manager.getFont("Kanit");
	_text = sf::Text("00:00", _font, 20);

	sf::Vector2f window_size = m_data->m_window.getView().getSize();
	sf::Vector2f pos = { window_size.x / 2, window_size.y };

	_game_clock = GameClock(_text, sf::Color::White, pos);
}

GameState::~GameState()
{
}

void GameState::handleInput(sf::Event& event)
{
	if (event.type == event.KeyReleased && event.key.code == sf::Keyboard::P)
	{
		_game_clock.Pause();
	}
	if (event.type == event.KeyReleased && event.key.code == sf::Keyboard::R)
	{
		_game_clock.Resume();
	}
}

void GameState::update()
{
	_game_clock.update();
}

void GameState::render(sf::RenderWindow& window)
{
	_game_clock.render(window);
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
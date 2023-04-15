#include "stdafx.h"
#include "GameState.h"
#include "PauseState.h"

GameState::GameState(GameDataRef data)
	: m_data(data)
{
	sf::Vector2f window_size = m_data->m_window.getView().getSize();
	sf::Font& font = m_data->asset_manager.getFont("Kanit");

	m_game_clock = GameClock(sf::Text("00:00", font, 20), sf::Color::White, { window_size.x / 2.f, window_size.y });

	_pause_btn = Button(sf::Text("Pause", font, 24), sf::Color::Black, sf::Color::Green, sf::Color::Yellow, { window_size.x * 0.06f , window_size.y * 0.04f });
}

GameState::~GameState()
{
}

void GameState::handleInput(sf::Event& event)
{
	// Button Hover
    sf::Vector2i mouse_pos = sf::Mouse::getPosition(m_data->m_window);

	_pause_btn.handleHover({ (float)mouse_pos.x, (float)mouse_pos.y });

	// Button Click
    if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
    {
        if (_pause_btn.contains({ (float)event.mouseButton.x, (float)event.mouseButton.y }))
        {
			Pause();
        }
    }

	if (event.type == event.KeyReleased && event.key.code == sf::Keyboard::Escape)
	{
		Pause();
	}
}

void GameState::update()
{
	m_game_clock.update();
}

void GameState::render(sf::RenderWindow& window)
{
	m_game_clock.render(window);
	_pause_btn.render(window);
}

void GameState::Init()
{
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
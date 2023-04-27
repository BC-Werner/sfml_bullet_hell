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
		_enemy(Random::Float(5.f, 50.f))
{
	sf::Vector2f window_size = m_data->m_window.getView().getSize();
	sf::Font& font = m_data->asset_manager.getFont("Kanit");
	sf::Texture& texture = m_data->asset_manager.getTexture("Triangle");

	m_game_clock = GameClock(
		sf::Text("00:00", font, 20), 
		sf::Color::White, 
		{ window_size.x / 2.f, window_size.y }
	);

	_pause_btn = Button(
		sf::Text("| |", font, 24), 
		sf::Color::Black, sf::Color::Green, sf::Color::Yellow, sf::Color::Blue,
		{ window_size.x * 0.06f , window_size.y * 0.04f },
		&(m_data->m_window)
	);

	//m_player.scale(0.05f);
	m_player.set_position({ window_size.x / 2.f, window_size.y / 2.f });

	_enemy.set_position({ 500.f, 500.f });
}

GameState::~GameState()
{
}

void GameState::handleInput(sf::Event& event)
{
	_pause_btn.handleInput(event);

	// Button Click
    if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
    {
        if (_pause_btn.contains({ (float)event.mouseButton.x, (float)event.mouseButton.y }))
        {
			Pause();
        }
    }

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
}

void GameState::update(float dt)
{
	m_game_clock.update(dt);
	_pause_btn.update(dt);
	m_player.update(dt);

	_enemy.update(dt);
}

void GameState::render(sf::RenderWindow& window)
{
	m_player.render(window);
	m_game_clock.render(window);
	_pause_btn.render(window);

	_enemy.render(window);
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
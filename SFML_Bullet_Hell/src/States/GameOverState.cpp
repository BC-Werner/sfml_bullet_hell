#include "stdafx.h"
#include "GameOverState.h"
#include "GameState.h"
#include "MainMenuState.h"

GameOverState::GameOverState(GameDataRef data)
	: m_data(data)
{
	sf::Font& font = m_data->asset_manager.getFont("Kanit");
	sf::Vector2f window_size = m_data->m_window.getView().getSize();

	m_gameover_text = CenteredText(sf::Text("GAME OVER", font, 48), { window_size.x / 2.f, window_size.y / 2.f });

	m_playagain_btn = Button(
		sf::Text("Play Again", font, 24), 
		sf::Color::Black, 
		sf::Color::Green, 
		sf::Color::Yellow, 
		{ window_size.x / 2.f, window_size.y * 0.6f}
	);
	m_mainmenu_btn = Button(
		sf::Text("Main Menu", font, 24), 
		sf::Color::Black, 
		sf::Color::Green, 
		sf::Color::Yellow, 
		{ window_size.x / 2.f, window_size.y * 0.7f}
	);
	m_quit_btn = Button(
		sf::Text("Quit Game", font, 24), 
		sf::Color::Black, 
		sf::Color::Red, 
		sf::Color::Yellow, 
		{ window_size.x / 2.f, window_size.y * 0.8f }
	);
}

void GameOverState::handleInput(sf::Event& event)
{
	// Button Hover
	m_playagain_btn.handleHover(m_data->m_window);
	m_mainmenu_btn.handleHover(m_data->m_window);
	m_quit_btn.handleHover(m_data->m_window);

	// Click
	if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
	{
		sf::Vector2f mouse_pos = { (float)event.mouseButton.x, (float)event.mouseButton.y };

		if (m_playagain_btn.contains(mouse_pos))
		{
			m_data->state_manager.AddState(StateRef(std::make_unique<GameState>(m_data)), true);
		}
		if (m_mainmenu_btn.contains(mouse_pos))
		{
			m_data->state_manager.AddState(StateRef(std::make_unique<MainMenuState>(m_data)), true);
		}
		if (m_quit_btn.contains(mouse_pos))
		{
			m_data->m_window.close();
		}
	}
}

void GameOverState::update()
{
	m_playagain_btn.update();
	m_mainmenu_btn.update();
	m_quit_btn.update();
}

void GameOverState::render(sf::RenderWindow& window)
{
	m_gameover_text.render(window);
	m_playagain_btn.render(window);
	m_mainmenu_btn.render(window);
	m_quit_btn.render(window);
}

void GameOverState::Init()
{
}

void GameOverState::Pause()
{
}

void GameOverState::Resume()
{
}

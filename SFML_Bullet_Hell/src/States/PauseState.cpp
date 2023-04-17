#include "stdafx.h"
#include "PauseState.h"
#include "MainMenuState.h"

PauseState::PauseState(GameDataRef data)
	: m_data(data)
{
	sf::Font& font = m_data->asset_manager.getFont("Kanit");
	sf::Vector2f window_size = m_data->m_window.getView().getSize();

	m_menuText = CenteredText(sf::Text("Paused", font, 48), { window_size.x / 2.f, window_size.y * 0.4f });

	m_resume_btn = Button(sf::Text("Resume", font, 24), sf::Color::Black, sf::Color::Green, sf::Color::Yellow, { window_size.x / 2.f, window_size.y * 0.5f });
	m_main_menu_btn = Button(sf::Text("Main Menu", font, 24), sf::Color::Black, sf::Color::Green, sf::Color::Yellow, { window_size.x / 2.f, window_size.y * 0.6f });
	m_quit_btn = Button(sf::Text("Quit Game", font, 24), sf::Color::Black, sf::Color::Red, sf::Color::Yellow, { window_size.x / 2.f, window_size.y * 0.7f });
}

void PauseState::handleInput(sf::Event& event)
{
	// Button Click
	if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
	{
		if (m_resume_btn.contains({ (float)event.mouseButton.x, (float)event.mouseButton.y }))
		{
			m_data->state_manager.PopState();
			m_data->state_manager.GetActiveState()->Resume();
			return;
		}
		if (m_main_menu_btn.contains({ (float)event.mouseButton.x, (float)event.mouseButton.y }))
		{
			m_data->state_manager.PopState();
			m_data->state_manager.AddState(StateRef(std::make_unique<MainMenuState>(m_data)), true);
			return;
		}
		if (m_quit_btn.contains({ (float)event.mouseButton.x, (float)event.mouseButton.y }))
		{
			m_data->m_window.close();
			return;
		}
	}
}

void PauseState::update()
{
	m_resume_btn.update(m_data->m_window);
	m_main_menu_btn.update(m_data->m_window);
	m_quit_btn.update(m_data->m_window);
}

void PauseState::render(sf::RenderWindow& window)
{
	m_menuText.render(window);
	m_resume_btn.render(window);
	m_main_menu_btn.render(window);
	m_quit_btn.render(window);
}

void PauseState::Init()
{
}

void PauseState::Pause()
{
}

void PauseState::Resume()
{
}

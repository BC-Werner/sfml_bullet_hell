#include "stdafx.h"
#include "MainMenuState.h"
#include "GameState.h"
#include "OptionsState.h"

MainMenuState::MainMenuState(GameDataRef data)
    : m_data(data)
{
    sf::Font& font = m_data->asset_manager.getFont("Kanit");
    sf::Vector2f window_size = m_data->m_window.getView().getSize();

    // Menu Text
    m_menuText = CenteredText(sf::Text("SFML BULLET HELL", font, 48), { window_size.x / 2.f, window_size.y * 0.4f });

	m_start_btn = Button(
		sf::Text("Start Game", font, 24), 
		sf::Color::Black, sf::Color::Green, sf::Color::Yellow, sf::Color::Blue,
		{ window_size.x / 2.f, window_size.y * 0.6f },
		&(m_data->m_window)
	);
	m_options_menu_btn = Button(
		sf::Text("Options", font, 24), 
		sf::Color::Black, sf::Color::Green, sf::Color::Yellow, sf::Color::Blue,
		{ window_size.x / 2.f, window_size.y * 0.7f },
		&(m_data->m_window)
	);
	m_quit_btn = Button(
		sf::Text("Quit Game", font, 24), 
		sf::Color::Black, sf::Color::Red, sf::Color::Yellow, sf::Color::Blue,
		{ window_size.x / 2.f, window_size.y * 0.8f },
		&(m_data->m_window)
	);
}

void MainMenuState::handleInput(sf::Event& event)
{
    m_start_btn.handleInput(event);
    m_options_menu_btn.handleInput(event);
    m_quit_btn.handleInput(event);

	// Click
    if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
    {
        if (m_start_btn.contains({ (float)event.mouseButton.x, (float)event.mouseButton.y }))
        {
            m_data->state_manager.AddState(StateRef(std::make_unique<GameState>(m_data)));
        }
        if (m_options_menu_btn.contains({ (float)event.mouseButton.x, (float)event.mouseButton.y }))
        {
            m_data->state_manager.AddState(StateRef(std::make_unique<OptionsState>(m_data)), false);
        }
        if (m_quit_btn.contains({ (float)event.mouseButton.x, (float)event.mouseButton.y }))
        {
            m_data->m_is_running = false;
        }
    }
}

void MainMenuState::update(float dt) 
{
    m_start_btn.update(dt);
    m_options_menu_btn.update(dt);
    m_quit_btn.update(dt);
}

void MainMenuState::render(sf::RenderWindow& window)
{
    m_menuText.render(window);
    m_start_btn.render(window);
    m_options_menu_btn.render(window);
    m_quit_btn.render(window);
}

void MainMenuState::Init()
{
}

void MainMenuState::Pause()
{
}

void MainMenuState::Resume()
{
}

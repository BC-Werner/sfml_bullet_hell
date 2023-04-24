#include "stdafx.h"
#include "MainMenuState.h"
#include "GameState.h"

MainMenuState::MainMenuState(GameDataRef data)
    : m_data(data)
{
    sf::Font& font = m_data->asset_manager.getFont("Kanit");
    sf::Vector2f window_size = m_data->m_window.getView().getSize();

    // Menu Text
    m_menuText = CenteredText(sf::Text("SFML BULLET HELL", font, 48), { window_size.x / 2.f, window_size.y * 0.4f });

    // Start Button
    sf::Text start_text = sf::Text("Start Game", font, 24);
    sf::Vector2f start_btn_pos = { window_size.x / 2, window_size.y * 0.6f};
    m_start_button = Button(start_text, sf::Color::Black, sf::Color::Green, sf::Color::Yellow, sf::Color::Blue, start_btn_pos, &(m_data->m_window));

    // Quit Button
    sf::Text quit_text = sf::Text("Quit Game", font, 24);
    sf::Vector2f quit_btn_pos = { window_size.x / 2, window_size.y * 0.7f};
    m_quit_button = Button(quit_text, sf::Color::Black, sf::Color::Red, sf::Color::Yellow, sf::Color::Blue, quit_btn_pos, &(m_data->m_window));
}

void MainMenuState::handleInput(sf::Event& event)
{
    m_start_button.handleInput(event);
    m_quit_button.handleInput(event);

	// Click
    if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
    {
        if (m_start_button.contains({ (float)event.mouseButton.x, (float)event.mouseButton.y }))
        {
            m_data->state_manager.AddState(StateRef(std::make_unique<GameState>(m_data)));
        }
        if (m_quit_button.contains({ (float)event.mouseButton.x, (float)event.mouseButton.y }))
        {
            m_data->m_window.close();
        }
    }
}

void MainMenuState::update(float dt) 
{
    m_start_button.update(dt);
    m_quit_button.update(dt);
}

void MainMenuState::render(sf::RenderWindow& window)
{
    m_menuText.render(window);
    m_start_button.render(window);
    m_quit_button.render(window);
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

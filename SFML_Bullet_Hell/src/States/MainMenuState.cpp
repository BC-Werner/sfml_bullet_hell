#include "stdafx.h"
#include "MainMenuState.h"
#include "GameState.h"

MainMenuState::MainMenuState(GameDataRef data)
    : m_data(data)
{
    m_font = m_data->asset_manager.getFont("Kanit");

    // Menu Text
    m_menuText = sf::Text("SFML BULLET HELL", m_font, 48);

    sf::Vector2f window_size = m_data->m_window.getView().getSize();
    sf::FloatRect menuRect = m_menuText.getGlobalBounds();

    m_menuText.setOrigin({
        m_menuText.getOrigin().x + menuRect.width / 2,
        m_menuText.getOrigin().y + menuRect.height / 2
	});

    m_menuText.setPosition({
        window_size.x / 2,
        window_size.y * 0.25f
	});

    // Start Button
    sf::Text start_text = sf::Text("Start Game", m_font, 24);
    sf::Vector2f start_btn_pos = { window_size.x / 2, window_size.y * 0.6f};
    m_start_button = Button(start_text, sf::Color::Black, sf::Color::Green, start_btn_pos);

    // Quit Button
    sf::Text quit_text = sf::Text("Quit Game", m_font, 24);
    sf::Vector2f quit_btn_pos = { window_size.x / 2, window_size.y * 0.73f};
    m_quit_button = Button(quit_text, sf::Color::Black, sf::Color::Red, quit_btn_pos);
}

void MainMenuState::handleInput(sf::Event& event)
{
	// Click
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        if (m_start_button.contains({ (float)event.mouseButton.x, (float)event.mouseButton.y }))
        {
            m_data->state_manager.AddState( StateRef(std::make_unique<GameState>(m_data)), false);
        }
        if (m_quit_button.contains({ (float)event.mouseButton.x, (float)event.mouseButton.y }))
        {
            m_data->m_window.close();
        }
    }
    // Hover
}

void MainMenuState::update() 
{
}

void MainMenuState::render(sf::RenderWindow& window)
{
    window.draw(m_menuText);
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

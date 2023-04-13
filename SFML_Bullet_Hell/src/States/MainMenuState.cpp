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
    start_text.setFillColor(sf::Color::Black);
    m_start_button = Button(start_text, sf::Color::Green, { 300.f,350.f });

    // Quit Button
    sf::Text quit_text = sf::Text("Start Game", m_font, 24);
    quit_text.setFillColor(sf::Color::Black);
    m_quit_button = Button(quit_text, sf::Color::Red, { 300.f,420.f });
}

void MainMenuState::handleInput(sf::Event& event)
{
	// Click
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        if (m_start_button.contains({ (float)event.mouseButton.x, (float)event.mouseButton.y }))
        {
            m_data->state_manager.AddState( StateRef(std::make_unique<GameState>(m_data)), true);
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

void MainMenuState::render(sf::RenderTarget& window)
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

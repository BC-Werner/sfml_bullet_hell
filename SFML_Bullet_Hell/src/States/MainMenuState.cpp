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
    m_start = Button(start_text, sf::Color::Green, { 300.f,350.f });

    // Quit Button
    sf::Text quit_text = sf::Text("Start Game", m_font, 24);
    quit_text.setFillColor(sf::Color::Black);
    m_quit = Button(quit_text, sf::Color::Red, { 300.f,420.f });
}

void MainMenuState::handleInput(sf::Event& event)
{
	// Click
    if (event.type == sf::Event::MouseButtonPressed)
    {
	/*
        if (event.mouseButton.button == sf::Mouse::Left &&
            m_startButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
        {
            // Transition to Gameplay
            std::cout << "Go to Gameplay" << std::endl;
			m_data->state_manager.AddState(StateRef(std::make_unique<GameState>(m_data)), false);
        }
        if (event.mouseButton.button == sf::Mouse::Left &&
            m_quitButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
        {
            std::cout << "Closing Game..." << std::endl;
            m_data->m_window.close();
        }
	*/
    }

/*
	// Hover
	//if (m_startButton.getGlobalBounds().contains(sf::Mouse::getPosition(m_data->m_window).x, sf::Mouse::getPosition(m_data->m_window).y))
	if (m_startButton.getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y))
	{
        startHovered = true;
        startLastFrameHovered = true;
	}
	else
	{
        startHovered = false;
	}

	if (m_quitButton.getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y))
	{
        quitHovered = true;
        quitLastFrameHovered = true;
	}
	else
	{
        quitHovered = false;
    }
*/
}

void MainMenuState::update() 
{
}

void MainMenuState::render(sf::RenderTarget& window)
{
    window.draw(m_menuText);
    m_start.render(window);
    m_quit.render(window);
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

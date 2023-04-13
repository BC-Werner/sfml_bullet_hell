#include "stdafx.h"
#include "MainMenuState.h"
#include "GameState.h"

MainMenuState::MainMenuState(GameDataRef data)
    : m_data(data)
{
    m_font = m_data->asset_manager.getFont("Kanit");
    m_menuText.setFont(m_font);
    m_menuText.setString("SFML BULLET HELL");
    m_menuText.setCharacterSize(48);
    m_startText.setFillColor(sf::Color::Red);
    m_menuText.setPosition(200.f, 200.f);

    m_startButton.setSize(sf::Vector2f(200.f, 50.f));
    m_startButton.setFillColor(sf::Color::Green);
    m_startButton.setPosition(300.f, 350.f);

    m_startText.setFont(m_font);
    m_startText.setString("Start Game");
    m_startText.setCharacterSize(24);
    m_startText.setFillColor(sf::Color::Red);
    m_startText.setPosition(340.f, 360.f);

    m_quitButton.setSize(sf::Vector2f(200.f, 50.f));
    m_quitButton.setFillColor(sf::Color::Red);
    m_quitButton.setPosition(300.f, 420.f);

    m_quitText.setFont(m_font);
    m_quitText.setString("Quit Game");
    m_quitText.setCharacterSize(24);
    m_quitText.setFillColor(sf::Color::Black);
    m_quitText.setPosition(340.f, 430.f);
}

void MainMenuState::handleInput(sf::Event& event)
{
	// Click
    if (event.type == sf::Event::MouseButtonPressed)
    {
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
    }

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
}

void MainMenuState::update() 
{
	if (startHovered)
	{
		m_startButton.setFillColor(sf::Color::Yellow);
		m_startButton.setPosition(300.f, 348.f);
		m_startText.setPosition(340.f, 358.f);
	}
    else if (startLastFrameHovered)
    {
		m_startButton.setFillColor(sf::Color::Green);
		m_startButton.setPosition(300.f, 350.f);
		m_startText.setPosition(340.f, 360.f);
        startLastFrameHovered = false;
    }

    if (quitHovered)
    {
		m_quitButton.setFillColor(sf::Color::Yellow);
		m_quitButton.setPosition(300.f, 418.f);
		m_quitText.setPosition(340.f, 428.f);
    }
    else if (quitLastFrameHovered)
    {
		m_quitButton.setFillColor(sf::Color::Red);
		m_quitButton.setPosition(300.f, 420.f);
		m_quitText.setPosition(340.f, 430.f);
        quitLastFrameHovered = false;
    }
}

void MainMenuState::render(sf::RenderTarget& window)
{
    window.draw(m_menuText);
    window.draw(m_startButton);
    window.draw(m_startText);
    window.draw(m_quitButton);
    window.draw(m_quitText);
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

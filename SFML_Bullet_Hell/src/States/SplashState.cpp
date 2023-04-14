#include "stdafx.h"
#include "SplashState.h"
#include "MainMenuState.h"

SplashState::SplashState(GameDataRef data)
	: m_data(data)
{
	m_font = m_data->asset_manager.getFont("Kanit");
	m_splashText.setString("A GAME\nBY\nBRANDON WERNER");
	m_splashText.setFont(m_font);
	m_splashText.setCharacterSize(36);
    //m_splashText.setFillColor(sf::Color::Red);
    m_splashText.setPosition(200.f, 200.f);
}

void SplashState::handleInput(sf::Event& event)
{
}

void SplashState::update()
{
	if (m_clock.getElapsedTime().asSeconds() > 2.0f)
	{
		m_data->state_manager.AddState(StateRef(std::make_unique<MainMenuState>(m_data)), true);
	}
}

void SplashState::render(sf::RenderWindow& window)
{
	m_data->m_window.draw(m_splashText);
}

void SplashState::Init()
{
}

void SplashState::Pause()
{
}

void SplashState::Resume()
{
}

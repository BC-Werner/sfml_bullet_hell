#include "stdafx.h"
#include "SplashState.h"
#include "MainMenuState.h"

SplashState::SplashState(GameDataRef data)
	: m_data(data)
{
	sf::Vector2f window_size = m_data->m_window.getView().getSize();

	m_splash_text = CenteredText(
		sf::Text("A GAME\nBY\nBRANDON WERNER", m_data->asset_manager.getFont("Kanit"), 48), 
		{window_size.x / 2.f, window_size.y / 2.f});
}

void SplashState::handleInput(sf::Event& event)
{
}

void SplashState::update(float dt)
{
	if (m_clock.getElapsedTime().asSeconds() > 2.0f)
	{
		m_data->state_manager.AddState(StateRef(std::make_unique<MainMenuState>(m_data)));
	}
}

void SplashState::render(sf::RenderWindow& window)
{
	m_splash_text.render(window);
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

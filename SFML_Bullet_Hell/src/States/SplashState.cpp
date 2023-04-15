#include "stdafx.h"
#include "SplashState.h"
#include "MainMenuState.h"

SplashState::SplashState(GameDataRef data)
	: m_data(data)
{
	m_font = m_data->asset_manager.getFont("Kanit");
	m_splashText = sf::Text("A GAME\nBY\nBRANDON WERNER", m_font, 36);

	sf::Vector2f bottom= sf::Vector2f(m_splashText.getGlobalBounds().width / 2.f, m_splashText.getGlobalBounds().height / 2.f);
	sf::Vector2f localBounds = { m_splashText.getLocalBounds().left, m_splashText.getLocalBounds().top };
	sf::Vector2f rounded = bottom + localBounds;

	m_splashText.setOrigin(rounded);

	sf::Vector2f window_size = m_data->m_window.getView().getSize();

	m_splashText.setPosition({ window_size.x / 2.f, window_size.y / 2.f });
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

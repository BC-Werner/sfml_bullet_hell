#include "stdafx.h"
#include "GameState.h"

GameState::GameState(GameDataRef data)
	: m_data(data)
{
	m_font = m_data->asset_manager.getFont("Kanit");

	m_timer_text = sf::Text("00:00", m_font, 20);
	m_timer_text.setFillColor(sf::Color::White);

	sf::Vector2f windowSize = m_data->m_window.getView().getSize();
	sf::FloatRect textBounds = m_timer_text.getGlobalBounds();

	m_timer_text.setOrigin({
		m_timer_text.getOrigin().x + textBounds.width / 2,
		m_timer_text.getOrigin().y + textBounds.height
	});
	m_timer_text.setPosition({
		windowSize.x / 2.f,
		windowSize.y - textBounds.height
	});
}

GameState::~GameState()
{
}

void GameState::handleInput(sf::Event& event)
{
}

void GameState::update()
{
	m_timer_text.setString( formatTime(m_clock.getElapsedTime().asSeconds()) );
}

void GameState::render(sf::RenderTarget& window)
{
	m_data->m_window.draw(m_timer_text);
}

void GameState::Init()
{
}

void GameState::Pause()
{
}

void GameState::Resume()
{
}

std::string GameState::formatTime(float seconds)
{
	int input = static_cast<int>(seconds);
	int min = input / 60;
	int sec = input % 60;

	return	(min < 10 ? '0' + std::to_string(min) : std::to_string(min)) 
			+ ":" +
			(sec < 10 ? '0' + std::to_string(sec) : std::to_string(sec));
}

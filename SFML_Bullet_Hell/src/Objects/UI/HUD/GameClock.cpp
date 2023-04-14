#include "stdafx.h"
#include "GameClock.h"

GameClock::Timer::Timer()
{
	bPaused = false;
	runtime = 0;
	m_c.restart();
}

void GameClock::Timer::Reset()
{
	m_c.restart();
	runtime = 0;
	bPaused = false;
}

void GameClock::Timer::Resume()
{
	if (bPaused) {
		m_c.restart();
	}
	bPaused = false;
}

void GameClock::Timer::Pause()
{
	if (!bPaused) {
		runtime += m_c.getElapsedTime().asSeconds();
	}
	bPaused = true;
}

float GameClock::Timer::GetElapsedSeconds()
{
	if (!bPaused) {
		return runtime + m_c.getElapsedTime().asSeconds();
	}
	return runtime;
}

GameClock::GameClock()
{
}

GameClock::GameClock(sf::Text text, sf::Color text_color, sf::Vector2f position)
	: m_text(text)
{
	const float PADDING = 5.f;
	sf::Vector2f bottom_center = sf::Vector2f(m_text.getGlobalBounds().width / 2.f, m_text.getGlobalBounds().height + PADDING);
	sf::Vector2f localBounds = { m_text.getLocalBounds().left, m_text.getLocalBounds().top };
	sf::Vector2f rounded = bottom_center + localBounds;

	m_text.setOrigin(rounded);
	m_text.setPosition(position);
	m_text.setFillColor(text_color);
}

GameClock::~GameClock()
{
}

void GameClock::update()
{
	m_text.setString( formatTime(m_timer.GetElapsedSeconds()) );
}

void GameClock::render(sf::RenderWindow& window)
{
	window.draw(m_text);
}

void GameClock::Pause()
{
	m_timer.Pause();
}

void GameClock::Resume()
{
	m_timer.Resume();
}

std::string GameClock::formatTime(float seconds)
{
	int input = static_cast<int>(seconds);
	int min = input / 60;
	int sec = input % 60;

	return	(min < 10 ? '0' + std::to_string(min) : std::to_string(min))
			+ ":" +
			(sec < 10 ? '0' + std::to_string(sec) : std::to_string(sec));
}

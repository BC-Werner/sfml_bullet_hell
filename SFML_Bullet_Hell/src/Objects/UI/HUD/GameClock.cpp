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
{
	const float PADDING = 5.f;
	text.setFillColor(text_color);
	m_centered_text = BottomCenteredText(text, { position.x, position.y - PADDING });
}

GameClock::~GameClock()
{
}

void GameClock::update()
{
	m_centered_text.setString( formatTime(m_timer.GetElapsedSeconds()) );
}

void GameClock::render(sf::RenderWindow& window)
{
	m_centered_text.render(window);
}

void GameClock::Pause()
{
	m_timer.Pause();
}

void GameClock::Resume()
{
	m_timer.Resume();
}

void GameClock::Restart()
{
	m_timer.Reset();
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
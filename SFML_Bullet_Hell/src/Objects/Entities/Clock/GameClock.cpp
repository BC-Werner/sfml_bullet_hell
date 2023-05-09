#include "stdafx.h"
#include "GameClock.h"

GameClock::GameClock()
{
	isPaused = false;
	runtime = 0.f;
	m_c.restart();
}

void GameClock::Restart()
{
	m_c.restart();
	runtime = 0.f;
	isPaused = false;
}

void GameClock::Resume()
{
	if (isPaused) {
		m_c.restart();
		isPaused = false;
	}
}

void GameClock::Pause()
{
	if (!isPaused) {
		runtime += m_c.getElapsedTime().asSeconds();
		isPaused = true;
	}
}

float GameClock::GetElapsedSeconds() const
{
	if (!isPaused) {
		return runtime + m_c.getElapsedTime().asSeconds();
	}
	return runtime;
}

std::string GameClock::to_string() const
{
	float seconds = GetElapsedSeconds();
	int input = static_cast<int>(seconds);
	int min = input / 60;
	int sec = input % 60;

	return	(min < 10 ? '0' + std::to_string(min) : std::to_string(min))
			+ ":" +
			(sec < 10 ? '0' + std::to_string(sec) : std::to_string(sec));
}

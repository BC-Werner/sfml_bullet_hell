#pragma once
#include "Objects/UI/Utility/BottomCenteredText.h"

class GameClock
{
// Private Inner Timer Class
private:
	class Timer {
	private:
		sf::Clock m_c;
		float runtime;
		bool isPaused;

	public:
		Timer();
		void Reset();
		void Resume(); 
		void Pause(); 
		float GetElapsedSeconds();
	};

public:
	GameClock();
	GameClock(sf::Text text, sf::Color text_color, sf::Vector2f position);
	~GameClock();

	void update();
	void render(sf::RenderWindow& window);

	void Pause();
	void Resume();
	void Restart();

private:
	std::string formatTime(float seconds);

private:
	BottomCenteredText m_centered_text;
	Timer m_timer;
};


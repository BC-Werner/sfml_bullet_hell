#pragma once

class GameClock
{
private:
	sf::Clock m_c;
	float runtime;
	bool isPaused;

public:
	GameClock();
	void Restart();
	void Resume(); 
	void Pause(); 
	float GetElapsedSeconds() const;
	std::string to_string() const;
};


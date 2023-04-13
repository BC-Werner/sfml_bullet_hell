#pragma once
#include "State.h"
#include "Game.h"

class GameState : public State
{
public:
	GameState(GameDataRef data);
	~GameState();

	virtual void handleInput(sf::Event& event) override;
	virtual void update() override;
	virtual void render(sf::RenderTarget& window) override;
	virtual void Init() override;
	virtual void Pause() override;
	virtual void Resume() override;

private:
	std::string formatTime(float seconds);

private:
	GameDataRef m_data;

	sf::Font m_font;
	sf::Text m_timer_text;
	sf::Clock m_clock;
	std::string m_time;
};


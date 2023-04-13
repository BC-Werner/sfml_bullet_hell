#pragma once
#include "State.h"
#include "Game.h"

class SplashState : public State
{
public:
	SplashState(GameDataRef data);

	virtual void handleInput(sf::Event& event) override;
	virtual void update() override;
	virtual void render(sf::RenderTarget& window) override;

	virtual void Init() override;
	virtual void Pause() override;
	virtual void Resume() override;

private:
	GameDataRef m_data;
	sf::Text m_splashText;
	sf::Font m_font;
	sf::Clock m_clock;
};


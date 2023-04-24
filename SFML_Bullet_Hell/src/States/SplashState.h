#pragma once
#include "State.h"
#include "Game.h"
#include "Objects/UI/Text/CenteredText.h"

class SplashState : public State
{
public:
	SplashState(GameDataRef data);

	virtual void handleInput(sf::Event& event) override;
	virtual void update(float dt) override;
	virtual void render(sf::RenderWindow& window) override;

	virtual void Init() override;
	virtual void Pause() override;
	virtual void Resume() override;

private:
	GameDataRef m_data;

	CenteredText m_splash_text;

	sf::Clock m_clock;
};


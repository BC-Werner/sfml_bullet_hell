#pragma once
#include "States/State.h"
#include "Game.h"
#include "Objects/UI/Text/CenteredText.h"
#include "Objects/UI/Menu/Button.h"

class GameOverState : public State
{
public: 
	GameOverState(GameDataRef data);
	~GameOverState() {};

	virtual void handleInput(sf::Event& event) override;
	virtual void update() override;
	virtual void render(sf::RenderWindow& window) override;
	virtual void Init() override;
	virtual void Pause() override;
	virtual void Resume() override;

private:
	GameDataRef m_data;
	CenteredText m_gameover_text;

	Button m_playagain_btn;
	Button m_quit_btn;
};


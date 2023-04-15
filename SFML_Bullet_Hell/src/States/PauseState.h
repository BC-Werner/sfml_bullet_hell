#pragma once
#include "State.h"
#include "Game.h"
#include "Objects/UI/Menu/Button.h"

class PauseState : public State
{
private:
	GameDataRef m_data;

    CenteredText m_menuText;

	Button m_resume_btn;
	Button m_main_menu_btn;
	Button m_quit_btn;

public:
	PauseState(GameDataRef data);
	~PauseState() {};

	virtual void handleInput(sf::Event& event) override;
	virtual void update() override;
	virtual void render(sf::RenderWindow& window) override;
	virtual void Init() override;
	virtual void Pause() override;
	virtual void Resume() override;
};


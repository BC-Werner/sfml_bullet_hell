#pragma once
#include "State.h"
#include "Game.h"
#include "Objects/UI/Menu/Button.h"

class OptionsState : public State
{
public:
	OptionsState(GameDataRef data);
	~OptionsState();

	virtual void handleInput(sf::Event& event) override;
	virtual void update(float dt) override;
	virtual void render(sf::RenderWindow& window) override;
	virtual void Init() override;
	virtual void Pause() override;
	virtual void Resume() override;

private:
	GameDataRef m_data;

    CenteredText m_menuText;

	Button m_fps_btn;
	Button m_back_btn;
};


#pragma once
#include "State.h"
#include "Game.h"
#include "Objects/UI/HUD/GameClock.h"
#include "Objects/UI/Menu/Button.h"
#include "Entities/Player/Player.h"

class GameState : public State
{
public:
	GameState(GameDataRef data);
	~GameState();

	virtual void handleInput(sf::Event& event) override;
	virtual void update(float dt) override;
	virtual void render(sf::RenderWindow& window) override;
	virtual void Init() override;
	virtual void Pause() override;
	virtual void Resume() override;

private:
	GameDataRef m_data;

	GameClock m_game_clock;
	Button _pause_btn;

	Player m_player;
};


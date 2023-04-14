#pragma once
#include "State.h"
#include "Game.h"
#include "Objects/UI/HUD/GameClock.h"

class GameState : public State
{
public:
	GameState(GameDataRef data);
	~GameState();

	virtual void handleInput(sf::Event& event) override;
	virtual void update() override;
	virtual void render(sf::RenderWindow& window) override;
	virtual void Init() override;
	virtual void Pause() override;
	virtual void Resume() override;

private:
	GameDataRef m_data;

	sf::Font _font;
	sf::Text _text;

	GameClock _game_clock;
};


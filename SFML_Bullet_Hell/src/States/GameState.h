#pragma once
#include "State.h"
#include "Game.h"
#include "Managers/EnemySpawner.h"
#include "Objects/Entities/Clock/GameClock.h"
#include "Objects/UI/Text/BottomCenteredText.h"
#include "Objects/UI/Menu/Button.h"
#include "Objects/Entities/Player/Player.h"
#include "Objects/Entities/Enemy/Enemy.h"
#include "Objects/Entities/Bullet/Bullet.h"

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
	EnemySpawner m_spawner;

	GameClock m_game_clock;
	BottomCenteredText m_game_clock_text;
	TopRightText m_health_text;

	Player m_player;

	sf::Clock m_spawn_clock;
	sf::Time m_spawn_time;
};


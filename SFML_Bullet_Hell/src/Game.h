#pragma once

#include "States/State.h"
#include "Managers/AssetManager.h"
#include "Managers/InputManager.h"
#include "Managers/StateManager.h"
#include "Objects/UI/Text/BottomLeftText.h"
#include "Random.h"

struct GameData
{
	sf::RenderWindow m_window;
	InputManager input_manager;
	AssetManager asset_manager;
	StateManager state_manager;
	Random& random_number_generator = Random::Get();
	bool m_is_running = true;
	bool m_show_fps = false;
};
typedef std::shared_ptr<GameData> GameDataRef;

class Game
{
// Properties
public:
private:
	GameDataRef m_data = std::make_shared<GameData>();
	sf::Event m_event;
	sf::Clock m_clock;
	sf::Time m_dt;

	BottomLeftText _fps;

// Methods
public:
	Game(int width, int height, const std::string& name);
	~Game();

	void run();

private:
	void initWindow(int width, int height, const std::string& name);
	void initStateMachine();
	void initResourceManager();

	void pollEvents();
	void handleInput();
	void updateDt();
	void update(float dt);
	void render();
};


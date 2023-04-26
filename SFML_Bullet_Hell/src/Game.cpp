#include "stdafx.h"
#include "Game.h"
#include "States/SplashState.h"

// Public
Game::Game(int width, int height, const std::string& name)
{
	initWindow(width, height, name);
	initResourceManager();
	initStateMachine();

	m_data->m_is_running = true;
	m_data->m_show_fps = false;

	_fps = BottomLeftText(sf::Text("00", m_data->asset_manager.getFont("Kanit"), 24), {5.f, m_data->m_window.getView().getSize().y -5.f});
}

Game::~Game()
{
}

void Game::run()
{
	while (m_data->m_is_running)
	{
		pollEvents();
		handleInput();
		updateDt();
		update(m_dt.asSeconds());
		render();
	}
	m_data->m_window.close();
}

void Game::initWindow(int width, int height, const std::string& name)
{
	m_data->m_window.create(sf::VideoMode(width, height), name, sf::Style::Close);
	m_data->m_window.setFramerateLimit(60);
}

void Game::initStateMachine()
{
	m_data->state_manager.AddState(std::make_unique<SplashState>(m_data));
	m_data->state_manager.ProcessStateChanges();
}

void Game::initResourceManager()
{
	m_data->asset_manager.LoadFont("Kanit", "resources/Kanit.ttf");
	m_data->asset_manager.LoadTexture("Triangle", "resources/triangle.png");
}

void Game::pollEvents()
{
	m_event = sf::Event();
	if (m_event.type == sf::Event::MouseButtonReleased)
		m_event = sf::Event();

	while (m_data->m_window.pollEvent(m_event))
	{
		if (m_event.type == sf::Event::Closed)
			m_data->m_window.close();
	}
}

void Game::handleInput()
{
	// Handle input in current State
	m_data->state_manager.GetActiveState()->handleInput(m_event);
}

void Game::updateDt()
{
	m_dt = m_clock.restart();

	if (m_data->m_show_fps)
	{
		int fps = 1000 / (int) m_dt.asMilliseconds();
		_fps.setString(std::to_string(fps));
	}
}

void Game::update(float dt)
{
	m_data->state_manager.ProcessStateChanges();
	// Update current State
	m_data->state_manager.GetActiveState()->update(dt);
}

void Game::render()
{
	m_data->m_window.clear();

	// Render Current State
	m_data->state_manager.GetActiveState()->render(m_data->m_window);

	if (m_data->m_show_fps)
	{
		_fps.render(m_data->m_window);
	}

	m_data->m_window.display();
}

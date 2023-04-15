#include "stdafx.h"
#include "Game.h"
#include "States/SplashState.h"

// Public
Game::Game(int width, int height, const std::string& name)
{
	initWindow(width, height, name);
	initResourceManager();
	initStateMachine();
}

Game::~Game()
{
}

void Game::run()
{
	while (m_data->m_window.isOpen())
	{
		pollEvents();
		handleInput();
		updateDt();
		update(m_dt.asSeconds());
		render();
	}
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
}

void Game::pollEvents()
{
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
	//if (m_event.type == sf::Event::MouseButtonPressed)
	//	std::cout << "MouseButtonPressed" << std::endl;
	//if (m_event.type == sf::Event::MouseButtonReleased)
	//	std::cout << "MouseButtonReleased" << std::endl;

	// Handle input in current State
	m_data->state_manager.GetActiveState()->handleInput(m_event);
}

void Game::updateDt()
{
	m_dt = m_clock.restart();
}

void Game::update(float dt)
{
	m_data->state_manager.ProcessStateChanges();
	// Update current State
	m_data->state_manager.GetActiveState()->update();
}

void Game::render()
{
	m_data->m_window.clear();

	// Render Current State
	m_data->state_manager.GetActiveState()->render(m_data->m_window);

	m_data->m_window.display();
}

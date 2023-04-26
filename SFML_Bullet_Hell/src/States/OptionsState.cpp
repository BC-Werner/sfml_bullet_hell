#include "stdafx.h"
#include "OptionsState.h"

OptionsState::OptionsState(GameDataRef data)
	: m_data(data)
{
	sf::Font& font = m_data->asset_manager.getFont("Kanit");
	sf::Vector2f window_size = m_data->m_window.getView().getSize();

	m_menuText = CenteredText(sf::Text("Options", font, 48), { window_size.x / 2.f, window_size.y * 0.4f });

	m_fps_btn = Button(
		sf::Text("Show FPS", font, 24), 
		sf::Color::Black, sf::Color::Green, sf::Color::Yellow, sf::Color::Blue,
		{ window_size.x / 2.f, window_size.y * 0.5f },
		&(m_data->m_window)
	);
	m_back_btn = Button(
		sf::Text("Back", font, 24), 
		sf::Color::Black, sf::Color::Green, sf::Color::Yellow, sf::Color::Blue,
		{ window_size.x / 2.f, window_size.y * 0.6f },
		&(m_data->m_window)
	);
}

OptionsState::~OptionsState()
{
}

void OptionsState::handleInput(sf::Event& event)
{
	m_fps_btn.handleInput(event);
	m_back_btn.handleInput(event);

	// Button Click
	if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
	{
		if (m_fps_btn.contains({ (float)event.mouseButton.x, (float)event.mouseButton.y }))
		{
			m_data->m_show_fps = !m_data->m_show_fps;
			return;
		}
		if (m_back_btn.contains({ (float)event.mouseButton.x, (float)event.mouseButton.y }))
		{
			m_data->state_manager.PopState();
			return;
		}
	}
}

void OptionsState::update(float dt)
{
	m_fps_btn.update(dt);
	m_back_btn.update(dt);
}

void OptionsState::render(sf::RenderWindow& window)
{
	m_menuText.render(window);
	m_fps_btn.render(window);
	m_back_btn.render(window);
}

void OptionsState::Init()
{
}

void OptionsState::Pause()
{
}

void OptionsState::Resume()
{
}

#include "State.h"
#include "Game.h"
#include "Objects/UI/Menu/Button.h"

#pragma once
class MainMenuState : public State
{
private:
    GameDataRef m_data;
    sf::Font m_font;

    // Menu Title
	sf::Text m_menuText;

    // Start Button
    Button m_start_button;

    // Quit Button
    Button m_quit_button;

public:
    MainMenuState(GameDataRef data);
    ~MainMenuState() {};

    void handleInput(sf::Event& event) override;
    void update() override;
    void render(sf::RenderTarget& window) override;

    void Init() override;
    void Pause() override;
    void Resume() override;
};


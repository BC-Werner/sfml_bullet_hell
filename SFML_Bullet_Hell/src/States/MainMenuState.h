#include "State.h"
#include "../Game.h"

#pragma once
class MainMenuState : public State
{
private:
    GameDataRef m_data;
    sf::Font m_font;

    // Menu Title
	sf::Text m_menuText;

    // Start Button
	sf::RectangleShape m_startButton;
    bool startHovered = false;
    bool startLastFrameHovered = false;
	sf::Text m_startText;

    // Quit Button
	sf::RectangleShape m_quitButton;
    bool quitHovered = false;
    bool quitLastFrameHovered = false;
	sf::Text m_quitText;

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


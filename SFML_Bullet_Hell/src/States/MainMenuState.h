#pragma once
#include "State.h"
#include "Game.h"
#include "Objects/UI/Menu/Button.h"
#include "Objects/UI/Text/CenteredText.h"

class MainMenuState : public State
{
private:
    GameDataRef m_data;

    CenteredText m_menuText;

    Button m_start_button;
    Button m_quit_button;

public:
    MainMenuState(GameDataRef data);
    ~MainMenuState() {};

    void handleInput(sf::Event& event) override;
    void update(float dt) override;
    void render(sf::RenderWindow& window) override;

    void Init() override;
    void Pause() override;
    void Resume() override;
};


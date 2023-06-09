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

    Button m_start_btn;
    Button m_options_menu_btn;
    Button m_quit_btn;

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


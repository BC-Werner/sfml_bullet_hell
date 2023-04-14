#pragma once
class State
{
public:
	State() {};
	virtual ~State() {};

	virtual void handleInput(sf::Event& event) = 0;
	virtual void update() = 0;
	virtual void render(sf::RenderWindow& window) = 0;

	virtual void Init() = 0;
	virtual void Pause() = 0;
	virtual void Resume() = 0;
private:
};


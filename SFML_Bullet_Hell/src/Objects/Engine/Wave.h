#pragma once

class Wave
{
public:
	Wave();
	~Wave();

	void Startup();
	void update(float dt);
	void Shutdown();

private:
	int m_enemies_per_interval;
	sf::Time m_spawn_interval;
};


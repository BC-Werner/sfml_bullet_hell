#pragma once
#include "Objects/Engine/Wave.h"

class WaveManager
{
public:
	WaveManager();
	~WaveManager();

	void load_waves();
	void update(float dt);

private:
	std::vector<Wave> m_waves;
};


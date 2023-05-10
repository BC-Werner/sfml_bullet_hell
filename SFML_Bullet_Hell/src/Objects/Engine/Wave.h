#pragma once

struct Wave
{
	int direction;
	int enemies_per_interval;
	sf::Time spawn_interval;
	sf::Time wave_end_time;
};


#pragma once

class HealthComponent
{
public:
	HealthComponent(unsigned max_health, float invincibility_time);
	~HealthComponent() {};

	void lose_health(unsigned damage);
	void gain_health(unsigned health);

	int get_health() const;
	void set_health(unsigned health);

	int get_max_health() const;
	void set_max_health(unsigned max_health);

	bool can_take_damage();

private:
	unsigned m_max_health;
	unsigned m_current_health;

	sf::Clock m_time_since_last_damage_taken;
	sf::Time m_invincibility_time;
};


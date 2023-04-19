#pragma once
#include "Objects/Components/Component.h"

class HealthComponent : public Component
{
public:
	HealthComponent(unsigned max_health);
	~HealthComponent() {};

	void lose_health(unsigned damage);
	void gain_health(unsigned health);

	int get_health() const;
	void set_health(unsigned health);

	int get_max_health() const;
	void set_max_health(unsigned max_health);

private:
	unsigned m_max_health;
	unsigned m_current_health;
};


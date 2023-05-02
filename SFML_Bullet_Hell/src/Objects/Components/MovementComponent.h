#pragma once

struct MoveFlags
{
	bool up;
	bool left;
	bool down;
	bool right;
	bool boost;
};

class MovementComponent
{
public:
	MovementComponent();
	~MovementComponent();

	void set_flags(MoveFlags flags);
	void update_position();

	sf::Vector2f get_position() const;
	void set_position(sf::Vector2f position);

private:

	MoveFlags m_flags;
	sf::Vector2f m_position;
	sf::Vector2f m_direction;
	float m_speed;
	const float M_MAX_SPEED;
};


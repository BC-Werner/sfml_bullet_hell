#include "stdafx.h"
#include "Random.h"

inline int Random::Int(int lower, int upper) { return Get()._Int(lower, upper); }

inline float Random::Float(float lower, float upper) { return Get()._Float(lower, upper); }

inline int Random::_Int(int lower, int upper)
{
	if (lower < upper)
	{
		std::uniform_int_distribution<int> dist(lower, upper);
		return dist(rng);
	}
	else
	{
		std::uniform_int_distribution<int> dist(upper, lower);
		return dist(rng);
	}
}

inline float Random::_Float(float lower, float upper)
{
	if (lower < upper)
	{
		std::uniform_real_distribution<float> dist(lower, upper);
		return dist(rng);
	}
	else
	{
		std::uniform_real_distribution<float> dist(upper, lower);
		return dist(rng);
	}
}

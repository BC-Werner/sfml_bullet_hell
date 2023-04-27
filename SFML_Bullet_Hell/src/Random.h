#pragma once
#include <random>

class Random
{
public:
	Random(const Random&) = delete;

	static Random& Get()
	{
		static Random instance;
		return instance;
	}

	static int Int(int lower, int upper);
	static float Float(float lower, float upper);

private:
	Random() { rng = std::mt19937(rd()); };

	int _Int(int lower, int upper);

	float _Float(float lower, float upper);

	std::random_device rd;
	std::mt19937 rng;

	int i = 0;
	float f = 0.f;
};


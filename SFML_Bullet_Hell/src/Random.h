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
	};

	static int Int(int lower, int upper) { return Get()._Int(lower, upper); };
	static float Float(float lower, float upper) { return Get()._Float(lower, upper); };

private:
	Random() { rng = std::mt19937(rd()); };

	int _Int(int lower, int upper)
	{
		std::uniform_int_distribution<int> dist(lower, upper);
		return dist(rng);
	};

	float _Float(float lower, float upper)
	{
		std::uniform_real_distribution<float> dist(lower, upper);
		return dist(rng);
	};

	std::random_device rd;
	std::mt19937 rng;

	int i = 0;
	float f = 0.f;
};


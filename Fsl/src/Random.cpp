#include <Fsl/Random.h>

namespace Fsl
{
	Random::Random(unsigned int seed)
	{
		SetSeed(seed);
	}

	void Random::SetSeed(unsigned int seed)
	{
		if (!seed) seed = 1;
		x = seed;
		y = seed + 1;
	}

	int Random::GetNextInt()
	{
		return GetNextInt(0, 0xffffffff);
	}

	int Random::GetNextInt(int high)
	{
		return GetNextInt(0, high);
	}

	int Random::GetNextInt(int low, int high)
	{
		x = 36969 * (x & 0xffff) + (x >> 16);
		y = 18000 * (y & 0xffff) + (y >> 16);
		return (x << 16) + y;
	}

	float Random::GetNextFloat()
	{
		return GetNextFloat(0.0f, 1.0f);
	}

	float Random::GetNextFloat(float high)
	{
		return GetNextFloat(0.0f, high);
	}

	float Random::GetNextFloat(float low, float high)
	{
		return ((GetNextInt() >> 16) & 32767) / 32767.0f * (high - low) + low;
	}
}

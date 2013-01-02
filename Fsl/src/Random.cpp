#include <Fsl/Random.h>

namespace Fsl
{
	Random::Random(unsigned int seed)
	{
		SetSeed(seed);
	}

	void Random::SetSeed(unsigned int seed)
	{
		this->seed = seed;
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
		seed = 0x00269ec3 + seed * 0x000343fd;
		return seed % (high - low) + low;
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

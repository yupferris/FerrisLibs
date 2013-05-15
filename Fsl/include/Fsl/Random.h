#ifndef __FSL_RANDOM_H__
#define __FSL_RANDOM_H__

namespace Fsl
{
	class Random
	{
	public:
		Random(unsigned int seed = 1);

		void SetSeed(unsigned int seed);

		int GetNextInt();
		int GetNextInt(int high);
		int GetNextInt(int low, int high);

		float GetNextFloat();
		float GetNextFloat(float high);
		float GetNextFloat(float low, float high);

	private:
		unsigned int x, y;
	};
}

#endif

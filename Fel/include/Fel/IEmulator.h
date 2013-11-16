#ifndef __FEL_IEMULATOR_H__
#define __FEL_IEMULATOR_H__

#include "IVideoDriver.h"
#include "IAudioDriver.h"

namespace Fel
{
	class IEmulator
	{
	public:
		virtual void Reset() = 0;
		virtual void CpuCyclesCallback(int numCycles) = 0;
	};
}

#endif

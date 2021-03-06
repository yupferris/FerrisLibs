#ifndef __FEL_ICPU_H__
#define __FEL_ICPU_H__

#include "IEmulator.h"

namespace Fel
{
	class ICpu
	{
	public:
		virtual void Reset() = 0;
		virtual int Run(int targetCycles) = 0;
	};
}

#endif

#ifndef __FEL_CPU_H__
#define __FEL_CPU_H__

#include "Emulator.h"

namespace Fel
{
	class Cpu
	{
	public:
		virtual void Reset() = 0;
	};
}

#endif

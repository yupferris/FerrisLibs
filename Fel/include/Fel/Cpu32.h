#ifndef __FEL_CPU32_H__
#define __FEL_CPU32_H__

#include "Cpu.h"
#include "Emulator32.h"

namespace Fel
{
	class Cpu32 : Cpu
	{
	public:
		Cpu32(Emulator32 *emulator);

	protected:
		Emulator32 *emulator;
	};
}

#endif

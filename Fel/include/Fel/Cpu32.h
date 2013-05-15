#ifndef __FEL_CPU32_H__
#define __FEL_CPU32_H__

#include "ICpu.h"
#include "IEmulator32.h"

namespace Fel
{
	class Cpu32 : ICpu
	{
	public:
		Cpu32(IEmulator32 *emulator);

	protected:
		IEmulator32 *emulator;
	};
}

#endif

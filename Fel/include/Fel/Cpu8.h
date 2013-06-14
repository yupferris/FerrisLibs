#ifndef __FEL_CPU8_H__
#define __FEL_CPU8_H__

#include "ICpu.h"
#include "IEmulator8.h"

namespace Fel
{
	class Cpu8 : ICpu
	{
	public:
		Cpu8(IEmulator8 *emulator);

	protected:
		IEmulator8 *emulator;
	};
}

#endif

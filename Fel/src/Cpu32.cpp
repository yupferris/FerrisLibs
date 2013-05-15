#include <Fel/Cpu32.h>

namespace Fel
{
	Cpu32::Cpu32(IEmulator32 *emulator)
	{
		this->emulator = emulator;
	}
}

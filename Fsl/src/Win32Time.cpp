#include <Fsl/Time.h>

#include <Windows.h>

namespace Fsl
{
	unsigned int Time::GetCurrent()
	{
		return timeGetTime();
	}
}

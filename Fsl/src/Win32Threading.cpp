#include <Fsl/Threading.h>

#include <Windows.h>

namespace Fsl
{
	void Threading::Sleep(int milliSecs)
	{
		::Sleep(milliSecs);
	}
}

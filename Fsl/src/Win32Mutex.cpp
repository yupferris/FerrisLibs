#include <Fsl/Win32Mutex.h>

namespace Fsl
{
	Mutex *Mutex::Create()
	{
		return new Win32Mutex();
	}

	Win32Mutex::Win32Mutex()
	{
		InitializeCriticalSection(&criticalSection);
	}

	Win32Mutex::~Win32Mutex()
	{
		DeleteCriticalSection(&criticalSection);
	}

	void Win32Mutex::Lock()
	{
		EnterCriticalSection(&criticalSection);
	}

	void Win32Mutex::Unlock()
	{
		LeaveCriticalSection(&criticalSection);
	}
}

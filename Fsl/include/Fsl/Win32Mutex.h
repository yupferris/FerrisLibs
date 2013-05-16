#ifndef __FSL_WIN32MUTEX_H__
#define __FSL_WIN32MUTEX_H__

#include "Mutex.h"

#include <Windows.h>

namespace Fsl
{
	class Win32Mutex : public Mutex
	{
	public:
		Win32Mutex();
		virtual ~Win32Mutex();

		virtual void Lock();
		virtual void Unlock();

	private:
		CRITICAL_SECTION criticalSection;
	};
}

#endif

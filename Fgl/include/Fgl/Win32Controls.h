#ifndef __FGL_WIN32CONTROLS_H__
#define __FGL_WIN32CONTROLS_H__

#include <Fsl.h>

#include <Windows.h>

namespace Fgl
{
	class Win32Controls
	{
	public:
		static void Init();

		static int GetNewId();
		static void RemoveId(int id);

		static void SetDefaultFont(HWND parentHandle, int id);

	private:
		static bool initialized;
		static Fsl::List<int> ids;
	};
}

#endif

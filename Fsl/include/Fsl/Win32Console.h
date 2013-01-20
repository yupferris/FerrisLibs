#ifndef __FSL_WIN32CONSOLE_H__
#define __FSL_WIN32CONSOLE_H__

#include "Console.h"

#include <Windows.h>

namespace Fsl
{
	class Win32Console
	{
	public:
		static void ResetColor();
		static ConsoleColor GetForegroundColor();
		static ConsoleColor GetBackgroundColor();
		static void SetForegroundColor(ConsoleColor color);
		static void SetBackgroundColor(ConsoleColor color);

	private:
		Win32Console();

		static Win32Console *get();

		void updateColors();

		HANDLE outputHandle;
		ConsoleColor defaultForegroundColor, defaultBackgroundColor;
		ConsoleColor currentForegroundColor, currentBackgroundColor;
	};
};

#endif

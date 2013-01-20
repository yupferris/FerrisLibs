#ifndef __FSL_CONSOLE_H__
#define __FSL_CONSOLE_H__

#include "String.h"

namespace Fsl
{
	enum class ConsoleColor
	{
		Black,
		DarkBlue,
		DarkGreen,
		DarkCyan,
		DarkRed,
		DarkMagenta,
		DarkYellow,
		Gray,
		DarkGray,
		Blue,
		Green,
		Cyan,
		Red,
		Magenta,
		Yellow,
		White,
	};

	class Console
	{
	public:
		static void Clear();
		static void Pause();

		static void Write(const String& s);
		static void WriteLine(const String& s = "");

		static char ReadChar();
		static int ReadInt();
		static float ReadFloat();
		static double ReadDouble();
		static String ReadLine();

		static void ResetColor();
		static ConsoleColor GetForegroundColor();
		static ConsoleColor GetBackgroundColor();
		static void SetForegroundColor(ConsoleColor color);
		static void SetBackgroundColor(ConsoleColor color);
	};
}

#endif

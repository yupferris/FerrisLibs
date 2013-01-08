#ifndef __FSL_CONSOLE_H__
#define __FSL_CONSOLE_H__

#include <Fsl/String.h>

namespace Fsl
{
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
	};
}

#endif

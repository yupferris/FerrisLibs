#ifndef __FSL_FILE_H__
#define __FSL_FILE_H__

#include "String.h"
#include "List.h"

namespace Fsl
{
	class File
	{
	public:
		static String ReadAllText(const String& path);
		static void WriteAllText(const String& path, const String& text);

		static List<unsigned char> ReadAllBytes(const String& path);
		static void WriteAllBytes(const String& path, const List<unsigned char>& bytes);
	};
}

#endif

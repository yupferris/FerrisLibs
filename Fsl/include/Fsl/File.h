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

		static int ReadBytes(const String& path, unsigned char *buf, int size);
		static void WriteBytes(const String& path, unsigned char *buf, int size);
	};
}

#endif

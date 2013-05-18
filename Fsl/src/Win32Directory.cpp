#include <Fsl/Directory.h>

#include <Windows.h>
#include <Shlwapi.h>

namespace Fsl
{
	String Directory::GetApplicationDirectory()
	{
		char executablePath[MAX_PATH + 1];
		for (int i = 0; i < MAX_PATH + 1; i++) executablePath[i] = 0;
		GetModuleFileName(GetModuleHandle(NULL), executablePath, MAX_PATH);
		String ret(executablePath);
		return ret.Substring(0, ret.LastIndexOf('\\'));
	}
}

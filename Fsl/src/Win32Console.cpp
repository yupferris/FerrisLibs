#include <Fsl/Console.h>

#include <Windows.h>

namespace Fsl
{
	void Console::Clear()
	{
		system("cls");
	}

	void Console::Pause()
	{
		system("pause");
	}
}

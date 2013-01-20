#include <Fsl/Win32Console.h>

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

	void Console::ResetColor()
	{
		Win32Console::ResetColor();
	}

	ConsoleColor Console::GetForegroundColor()
	{
		return Win32Console::GetForegroundColor();
	}

	ConsoleColor Console::GetBackgroundColor()
	{
		return Win32Console::GetBackgroundColor();
	}

	void Console::SetForegroundColor(ConsoleColor color)
	{
		Win32Console::SetForegroundColor(color);
	}

	void Console::SetBackgroundColor(ConsoleColor color)
	{
		Win32Console::SetBackgroundColor(color);
	}

	void Win32Console::ResetColor()
	{
		auto console = get();
		console->currentForegroundColor = console->defaultForegroundColor;
		console->currentBackgroundColor = console->defaultBackgroundColor;
		console->updateColors();
	}

	ConsoleColor Win32Console::GetForegroundColor()
	{
		return get()->currentForegroundColor;
	}

	ConsoleColor Win32Console::GetBackgroundColor()
	{
		return get()->currentBackgroundColor;
	}

	void Win32Console::SetForegroundColor(ConsoleColor color)
	{
		auto console = get();
		console->currentForegroundColor = color;
		console->updateColors();
	}

	void Win32Console::SetBackgroundColor(ConsoleColor color)
	{
		auto console = get();
		console->currentBackgroundColor = color;
		console->updateColors();
	}

	Win32Console::Win32Console()
	{
		outputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
		if (outputHandle == INVALID_HANDLE_VALUE) throw FSL_EXCEPTION("Could not get standard output handle");
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		if (!GetConsoleScreenBufferInfo(outputHandle, &csbi)) throw FSL_EXCEPTION("Could not get console info");
		currentForegroundColor = defaultForegroundColor = (ConsoleColor)(csbi.wAttributes & 0x0f);
		currentBackgroundColor = defaultBackgroundColor = (ConsoleColor)((csbi.wAttributes >> 4) & 0x0f);
	}

	Win32Console *Win32Console::get()
	{
		static Win32Console console;
		return &console;
	}

	void Win32Console::updateColors()
	{
		SetConsoleTextAttribute(outputHandle, ((int)currentBackgroundColor << 4) | (int)currentForegroundColor);
	}
}

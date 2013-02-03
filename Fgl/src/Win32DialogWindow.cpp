#include <Fgl/DialogWindow.h>
#include <Fgl/Win32Window.h>

#include <Windows.h>

using namespace Fsl;

namespace Fgl
{
	String DialogWindow::OpenFile(const String& caption)
	{
		return OpenFile(nullptr, caption);
	}

	String DialogWindow::OpenFile(Window *parentWindow, const String& caption)
	{
		auto fileName = new char[MAX_PATH];
		for (int i = 0; i < MAX_PATH; i++) fileName[i] = '\0';
		OPENFILENAME ofn =
		{
			sizeof(OPENFILENAME),
			parentWindow ? (HWND)parentWindow->GetNativeHandle() : NULL,
			0,
			"All Files (*.*)\n*.*\0", // TODO: filters
			0, 0,
			1,
			fileName,
			MAX_PATH,
			0, 0, 0,
			caption.GetData(),
			0, 0, 0, 0, 0, 0, 0, 0, 0
		};
		String ret = GetOpenFileName(&ofn) ? fileName : "";
		delete [] fileName;
		return ret;
	}
}

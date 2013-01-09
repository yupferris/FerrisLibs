#ifndef __FGL_WIN32MESSAGEWINDOW_H__
#define __FGL_WIN32MESSAGEWINDOW_H__

#include "MessageWindow.h"
#include "Win32Window.h"

#include <Windows.h>

namespace Fgl
{
	class Win32MessageWindow
	{
	public:
		static MessageWindow::Response Show(Win32Window *window, const Fsl::String& text, const Fsl::String& caption, MessageWindow::Buttons buttons, UINT boxType);
	};
}

#endif

#ifndef __FGL_DIALOGWINDOW_H__
#define __FGL_DIALOGWINDOW_H__

#include <Fsl.h>

#include "Window.h"

namespace Fgl
{
	class DialogWindow
	{
	public:
		static Fsl::String OpenFile(const Fsl::String& caption = "");
		static Fsl::String OpenFile(Window *parentWindow, const Fsl::String& caption = "");
	};
}

#endif

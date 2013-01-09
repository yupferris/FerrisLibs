#ifndef __FGL_MESSAGEWINDOW_H__
#define __FGL_MESSAGEWINDOW_H__

#include "Window.h"

#include <Fsl.h>

namespace Fgl
{
	class MessageWindow
	{
	public:
		enum class Buttons
		{
			Ok,
			OkCancel,
			YesNo,
		};

		enum class Response
		{
			Ok,
			Cancel,
			Yes,
			No,
		};

		static Response Info(const Fsl::String& text, Buttons buttons = Buttons::Ok);
		static Response Question(const Fsl::String& text, Buttons buttons = Buttons::YesNo);
		static Response Warning(const Fsl::String& text, Buttons buttons = Buttons::Ok);
		static Response Error(const Fsl::String& text, Buttons buttons = Buttons::Ok);

		static Response Info(const Fsl::String& text, const Fsl::String& caption, Buttons buttons = Buttons::Ok);
		static Response Question(const Fsl::String& text, const Fsl::String& caption, Buttons buttons = Buttons::YesNo);
		static Response Warning(const Fsl::String& text, const Fsl::String& caption, Buttons buttons = Buttons::Ok);
		static Response Error(const Fsl::String& text, const Fsl::String& caption, Buttons buttons = Buttons::Ok);

		static Response Info(Window *window, const Fsl::String& text, Buttons buttons = Buttons::Ok);
		static Response Question(Window *window, const Fsl::String& text, Buttons buttons = Buttons::YesNo);
		static Response Warning(Window *window, const Fsl::String& text, Buttons buttons = Buttons::Ok);
		static Response Error(Window *window, const Fsl::String& text, Buttons buttons = Buttons::Ok);

		static Response Info(Window *window, const Fsl::String& text, const Fsl::String& caption, Buttons buttons = Buttons::Ok);
		static Response Question(Window *window, const Fsl::String& text, const Fsl::String& caption, Buttons buttons = Buttons::YesNo);
		static Response Warning(Window *window, const Fsl::String& text, const Fsl::String& caption, Buttons buttons = Buttons::Ok);
		static Response Error(Window *window, const Fsl::String& text, const Fsl::String& caption, Buttons buttons = Buttons::Ok);
	};
}

#endif

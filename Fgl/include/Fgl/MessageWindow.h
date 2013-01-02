#ifndef __FGL_MESSAGEWINDOW_H__
#define __FGL_MESSAGEWINDOW_H__

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
	};
}

#endif

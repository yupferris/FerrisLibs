#include <Fgl/Win32MessageWindow.h>

using namespace Fsl;

namespace Fgl
{
	MessageWindow::Response MessageWindow::Info(const String& text, Buttons buttons)
	{
		return Info(text, "", buttons);
	}

	MessageWindow::Response MessageWindow::Question(const String& text, Buttons buttons)
	{
		return Question(text, "", buttons);
	}

	MessageWindow::Response MessageWindow::Warning(const String& text, Buttons buttons)
	{
		return Warning(text, "", buttons);
	}

	MessageWindow::Response MessageWindow::Error(const String& text, Buttons buttons)
	{
		return Error(text, "", buttons);
	}

	MessageWindow::Response MessageWindow::Info(const String& text, const String& caption, Buttons buttons)
	{
		return Info(nullptr, text, caption, buttons);
	}

	MessageWindow::Response MessageWindow::Question(const String& text, const String& caption, Buttons buttons)
	{
		return Question(nullptr, text, caption, buttons);
	}

	MessageWindow::Response MessageWindow::Warning(const String& text, const String& caption, Buttons buttons)
	{
		return Warning(nullptr, text, caption, buttons);
	}

	MessageWindow::Response MessageWindow::Error(const String& text, const String& caption, Buttons buttons)
	{
		return Error(nullptr, text, caption, buttons);
	}

	MessageWindow::Response MessageWindow::Info(Window *window, const String& text, Buttons buttons)
	{
		return Info(window, text, "", buttons);
	}

	MessageWindow::Response MessageWindow::Question(Window *window, const String& text, Buttons buttons)
	{
		return Question(window, text, "", buttons);
	}

	MessageWindow::Response MessageWindow::Warning(Window *window, const String& text, Buttons buttons)
	{
		return Warning(window, text, "", buttons);
	}

	MessageWindow::Response MessageWindow::Error(Window *window, const String& text, Buttons buttons)
	{
		return Error(window, text, "", buttons);
	}

	MessageWindow::Response MessageWindow::Info(Window *window, const String& text, const String& caption, Buttons buttons)
	{
		return Win32MessageWindow::Show((Win32Window *)window, text, caption, buttons, MB_ICONINFORMATION);
	}

	MessageWindow::Response MessageWindow::Question(Window *window, const String& text, const String& caption, Buttons buttons)
	{
		return Win32MessageWindow::Show((Win32Window *)window, text, caption, buttons, MB_ICONQUESTION);
	}

	MessageWindow::Response MessageWindow::Warning(Window *window, const String& text, const String& caption, Buttons buttons)
	{
		return Win32MessageWindow::Show((Win32Window *)window, text, caption, buttons, MB_ICONWARNING);
	}

	MessageWindow::Response MessageWindow::Error(Window *window, const String& text, const String& caption, Buttons buttons)
	{
		return Win32MessageWindow::Show((Win32Window *)window, text, caption, buttons, MB_ICONERROR);
	}

	MessageWindow::Response Win32MessageWindow::Show(Win32Window *window, const String& text, const String& caption, MessageWindow::Buttons buttons, UINT boxType)
	{
		switch (buttons)
		{
		case MessageWindow::Buttons::Ok: boxType |= MB_OK; break;
		case MessageWindow::Buttons::OkCancel: boxType |= MB_OKCANCEL; break;
		case MessageWindow::Buttons::YesNo: boxType |= MB_YESNO; break;
		default: throw FSL_EXCEPTION("Invalid message window buttons specified");
		}

		switch (MessageBox(window ? window->GetHandle() : NULL, text.GetData(), caption.GetData(), boxType))
		{
		case IDOK: return MessageWindow::Response::Ok;
		case IDCANCEL: return MessageWindow::Response::Cancel;
		case IDYES: return MessageWindow::Response::Yes;
		case IDNO: return MessageWindow::Response::No;
		}
		throw FSL_EXCEPTION("Invalid message window response");
	}
}

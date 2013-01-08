#include <Fgl/Win32MessageWindow.h>

using namespace Fsl;

namespace Fgl
{
	MessageWindow::Response MessageWindow::Info(const String& text, Buttons buttons)
	{
		return Win32MessageWindow::Show(text, "", buttons, MB_ICONINFORMATION);
	}

	MessageWindow::Response MessageWindow::Question(const String& text, Buttons buttons)
	{
		return Win32MessageWindow::Show(text, "", buttons, MB_ICONQUESTION);
	}

	MessageWindow::Response MessageWindow::Warning(const String& text, Buttons buttons)
	{
		return Win32MessageWindow::Show(text, "", buttons, MB_ICONWARNING);
	}

	MessageWindow::Response MessageWindow::Error(const String& text, Buttons buttons)
	{
		return Win32MessageWindow::Show(text, "", buttons, MB_ICONERROR);
	}

	MessageWindow::Response MessageWindow::Info(const String& text, const String& caption, Buttons buttons)
	{
		return Win32MessageWindow::Show(text, caption, buttons, MB_ICONINFORMATION);
	}

	MessageWindow::Response MessageWindow::Question(const String& text, const String& caption, Buttons buttons)
	{
		return Win32MessageWindow::Show(text, caption, buttons, MB_ICONQUESTION);
	}

	MessageWindow::Response MessageWindow::Warning(const String& text, const String& caption, Buttons buttons)
	{
		return Win32MessageWindow::Show(text, caption, buttons, MB_ICONWARNING);
	}

	MessageWindow::Response MessageWindow::Error(const String& text, const String& caption, Buttons buttons)
	{
		return Win32MessageWindow::Show(text, caption, buttons, MB_ICONERROR);
	}

	MessageWindow::Response Win32MessageWindow::Show(const String& text, const String& caption, MessageWindow::Buttons buttons, UINT boxType)
	{
		switch (buttons)
		{
		case MessageWindow::Buttons::Ok: boxType |= MB_OK; break;
		case MessageWindow::Buttons::OkCancel: boxType |= MB_OKCANCEL; break;
		case MessageWindow::Buttons::YesNo: boxType |= MB_YESNO; break;
		default: throw FSL_EXCEPTION("Invalid message window buttons specified");
		}

		switch (MessageBox(NULL, text.GetData(), caption.GetData(), boxType))
		{
		case IDOK: return MessageWindow::Response::Ok;
		case IDCANCEL: return MessageWindow::Response::Cancel;
		case IDYES: return MessageWindow::Response::Yes;
		case IDNO: return MessageWindow::Response::No;
		}
		throw FSL_EXCEPTION("Invalid message window response");
	}
}

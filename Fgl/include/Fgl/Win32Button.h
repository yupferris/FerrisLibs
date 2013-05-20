#ifndef __FGL_WIN32BUTTON_H__
#define __FGL_WIN32BUTTON_H__

#include <Fgl/Button.h>
#include <Fgl/IWin32HandleCommandMessage.h>

#include <Windows.h>

namespace Fgl
{
	class Win32Button : public Button, public IWin32HandleCommandMessage
	{
	public:
		Win32Button();
		virtual ~Win32Button();

		virtual void SetParent(IWidgetParent *parent);

		virtual void SetPos(int x, int y);
		virtual void SetSize(int width, int height);

		HWND GetHandle() const;

		virtual void HandleCommandMessage(LPARAM wParam);

	private:
		void layoutChanged();
		void destroyWindow();

		int id;
		HWND handle;
	};
}

#endif

#ifndef __FGL_WIN32WINDOW_H__
#define __FGL_WIN32WINDOW_H__

#include "Window.h"
#include "Win32Menu.h"

#include <Windows.h>

namespace Fgl
{
	class Win32Window : public Window
	{
	public:
		Win32Window(const Fsl::String& title, int desiredWidth, int desiredHeight, bool fullscreen);
		virtual ~Win32Window();

		virtual void Update();

		virtual void SetDesiredSize(int desiredWidth, int desiredHeight);

		virtual void SetMenu(Menu *menu);

		virtual void SetContent(Widget *widget);

		virtual void *GetNativeHandle() const;

	private:
		void resetLayout();

		LRESULT CALLBACK wndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
		static LRESULT CALLBACK wndProcRouter(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);

		static Key wParamToKey(WPARAM wParam);

		static int classRefCount;
		static Fsl::String className;

		DWORD nativeStyle;
		HWND handle;

		Win32Menu *menu;
	};
}

#endif

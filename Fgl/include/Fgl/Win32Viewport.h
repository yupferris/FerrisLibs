#ifndef __FGL_WIN32VIEWPORT_H__
#define __FGL_WIN32VIEWPORT_H__

#include "Viewport.h"

#include <Windows.h>

namespace Fgl
{
	class Win32Viewport : public Viewport
	{
	public:
		Win32Viewport();
		virtual ~Win32Viewport();

		virtual void SetParent(IWidgetParent *parent);

		virtual void SetPos(int x, int y);
		virtual void SetSize(int width, int height);

		HWND GetHandle() const;

	private:
		void layoutChanged();
		void destroyWindow();

		LRESULT CALLBACK wndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
		static LRESULT CALLBACK wndProcRouter(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);

		static int classRefCount;
		static Fsl::String className;

		HWND handle;
	};
}

#endif

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

		virtual void *GetNativeHandle() const;

		virtual void SetParent(IWidgetParent *parent);

		virtual void SetPos(int x, int y);
		virtual void SetSize(int width, int height);

	private:
		void layoutChanged();

		LRESULT CALLBACK wndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
		static LRESULT CALLBACK wndProcRouter(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);

		static int classRefCount;
		static Fsl::String className;

		HWND handle;
	};
}

#endif

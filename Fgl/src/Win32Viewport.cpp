#include <Fgl/Win32Viewport.h>
#include <Fgl/IWidgetParent.h>

using namespace Fsl;

namespace Fgl
{
	Viewport *Viewport::Create()
	{
		return new Win32Viewport();
	}

	int Win32Viewport::classRefCount = 0;
	String Win32Viewport::className = "FglViewport";

	Win32Viewport::Win32Viewport()
	{
		if (!classRefCount)
		{
			WNDCLASSEX wndClass =
			{
				sizeof(WNDCLASSEX),
				0,
				wndProcRouter,
				0, 0,
				GetModuleHandle(NULL),
				NULL,
				LoadCursor(NULL, IDC_ARROW),
				(HBRUSH)GetStockObject(BLACK_BRUSH),
				NULL,
				className.GetData(),
				NULL
			};
			if (!RegisterClassEx(&wndClass)) throw FSL_EXCEPTION("Couldn't register viewport class");
		}
		classRefCount++;

		handle = NULL;
	}
	
	Win32Viewport::~Win32Viewport()
	{
		destroyWindow();
		classRefCount--;
		if (!classRefCount) UnregisterClass(className.GetData(), GetModuleHandle(NULL));
	}

	void Win32Viewport::SetParent(IWidgetParent *parent)
	{
		destroyWindow();
		Widget::SetParent(parent);
		if (parent) handle = CreateWindow(className.GetData(), "Viewport", WS_VISIBLE | WS_CHILD, GetDesiredX(), GetDesiredY(), GetDesiredWidth(), GetDesiredHeight(), (HWND)parent->GetNativeHandle(), NULL, GetModuleHandle(NULL), this);
	}

	void Win32Viewport::SetPos(int x, int y)
	{
		Widget::SetPos(x, y);
		layoutChanged();
	}

	void Win32Viewport::SetSize(int width, int height)
	{
		Widget::SetSize(width, height);
		layoutChanged();
	}

	HWND Win32Viewport::GetHandle() const
	{
		return handle;
	}

	void Win32Viewport::HandleCommandMessage(LPARAM wParam)
	{
	}

	void Win32Viewport::layoutChanged()
	{
		SetWindowPos(handle, 0, GetX(), GetY(), GetWidth(), GetHeight(), 0);
	}

	void Win32Viewport::destroyWindow()
	{
		if (handle)
		{
			DestroyWindow(handle);
			handle = NULL;
		}
	}

	LRESULT CALLBACK Win32Viewport::wndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
	{
		return DefWindowProc(hWnd, Msg, wParam, lParam);
	}

	LRESULT CALLBACK Win32Viewport::wndProcRouter(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
	{
		Win32Viewport *viewport = nullptr;
		switch (Msg)
		{
		case WM_GETMINMAXINFO:
			return DefWindowProc(hWnd, Msg, wParam, lParam);

		case WM_NCCREATE:
			viewport = (Win32Viewport *)((LPCREATESTRUCT)lParam)->lpCreateParams;
			viewport->handle = hWnd;
			SetWindowLongPtr(hWnd, GWL_USERDATA, (LONG_PTR)viewport);
			break;

		default:
			viewport = (Win32Viewport *)GetWindowLong(hWnd, GWL_USERDATA);
		}
		if (!viewport) throw FSL_EXCEPTION("Viewport proc router invoked without a viewport handle");

		return viewport->wndProc(hWnd, Msg, wParam, lParam);
	}
}

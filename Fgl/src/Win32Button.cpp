#include <Fgl/Win32Button.h>
#include <Fgl/IWidgetParent.h>
#include <Fgl/Win32Controls.h>

using namespace Fsl;

namespace Fgl
{
	Button *Button::Create(const String& text)
	{
		return new Win32Button(text);
	}

	Win32Button::Win32Button(const String& text)
		: Button(text)
	{
		handle = NULL;
	}

	Win32Button::~Win32Button()
	{
		destroyWindow();
	}

	void Win32Button::SetParent(IWidgetParent *parent)
	{
		destroyWindow();
		Widget::SetParent(parent);
		if (parent)
		{
			Win32Controls::Init();
			id = Win32Controls::GetNewId();
			auto parentHandle = (HWND)parent->GetNativeHandle();
			handle = CreateWindow("BUTTON", GetText().GetData(), WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, GetDesiredX(), GetDesiredY(), GetDesiredWidth(), GetDesiredHeight(), parentHandle, (HMENU)id, GetModuleHandle(NULL), this);
			SendDlgItemMessage(parentHandle, id, WM_SETFONT, (WPARAM)GetStockObject(DEFAULT_GUI_FONT), MAKELPARAM(TRUE, 0));
		}
	}

	void Win32Button::SetPos(int x, int y)
	{
		Widget::SetPos(x, y);
		layoutChanged();
	}

	void Win32Button::SetSize(int width, int height)
	{
		Widget::SetSize(width, height);
		layoutChanged();
	}

	HWND Win32Button::GetHandle() const
	{
		return handle;
	}

	void Win32Button::HandleCommandMessage(LPARAM wParam)
	{
		if (LOWORD(wParam) == id) Click();
	}

	void Win32Button::layoutChanged()
	{
		SetWindowPos(handle, 0, GetX(), GetY(), GetWidth(), GetHeight(), 0);
	}

	void Win32Button::destroyWindow()
	{
		if (handle)
		{
			Win32Controls::RemoveId(id);
			DestroyWindow(handle);
			handle = NULL;
		}
	}
}

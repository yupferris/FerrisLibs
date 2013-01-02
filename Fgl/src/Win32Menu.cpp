#include <Fgl/Win32Menu.h>
#include <Fgl/Win32Window.h>

using namespace Fsl;

namespace Fgl
{
	Menu *Menu::Create(const String& text)
	{
		return new Win32Menu(text);
	}

	Win32Menu::Win32Menu(const String& text)
		: Menu(text)
	{
		handle = CreateMenu();
		window = nullptr;
	}

	Win32Menu::~Win32Menu()
	{
		int numItems = GetMenuItemCount(handle);
		if (numItems > 0)
		{
			for (int i = 0; i < numItems; i++)
			{
				if (GetSubMenu(handle, i))
				{
					RemoveMenu(handle, i, MF_BYPOSITION);
					i--;
				}
			}
		}
		DestroyMenu(handle);
	}

	void Win32Menu::AddChild(Menu *child)
	{
		auto win32Child = (Win32Menu *)child;
		if (childMenus.Contains(win32Child)) throw FSL_EXCEPTION("Menu already contains the given child menu");
		if (!AppendMenu(handle, MF_STRING | MF_POPUP, (UINT_PTR)win32Child->GetHandle(), win32Child->GetText().GetData())) throw FSL_EXCEPTION("Could not add child menu");
		childMenus.Add(win32Child);
	}

	void Win32Menu::AddChild(MenuItem *child)
	{
		auto win32Child = (Win32MenuItem *)child;
		if (childItems.Contains(win32Child)) throw FSL_EXCEPTION("Menu already contains the given child");
		if (!AppendMenu(handle, MF_STRING, (UINT_PTR)win32Child->GetId(), win32Child->GetText().GetData())) throw FSL_EXCEPTION("Could not add child to menu");
		childItems.Add(win32Child);
	}

	void Win32Menu::AddSeparator()
	{
		if (!AppendMenu(handle, MF_SEPARATOR, 0, nullptr)) throw FSL_EXCEPTION("Could not add separator to menu");
	}

	HMENU Win32Menu::GetHandle() const
	{
		return handle;
	}

	Win32Window *Win32Menu::GetWindow() const
	{
		return window;
	}

	void Win32Menu::SetWindow(Win32Window *window)
	{
		if (window && this->window) throw FSL_EXCEPTION("Menu already set to another window");
		this->window = window;
	}

	void Win32Menu::HandleCommandMessage(LPARAM wParam)
	{
		for (int i = 0; i < childItems.Count(); i++)
		{
			if (LOWORD(wParam) == childItems[i]->GetId())
			{
				childItems[i]->OnClick();
				return;
			}
		}
		for (int i = 0; i < childMenus.Count(); i++) childMenus[i]->HandleCommandMessage(wParam);
	}
}

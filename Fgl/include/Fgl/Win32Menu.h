#ifndef __FGL_WIN32MENU_H__
#define __FGL_WIN32MENU_H__

#include "Menu.h"
#include "Win32MenuItem.h"

#include <Windows.h>

namespace Fgl
{
	class Win32Window;

	class Win32Menu : public Menu
	{
	public:
		Win32Menu(const Fsl::String& text);
		virtual ~Win32Menu();

		virtual void AddChild(Menu *child);
		virtual void AddChild(MenuItem *child);
		virtual void AddSeparator();

		HMENU GetHandle() const;

		Win32Window *GetWindow() const;
		void SetWindow(Win32Window *window);

		void HandleCommandMessage(LPARAM wParam);

	private:
		HMENU handle;
		Win32Window *window;
		Fsl::List<Win32Menu *> childMenus;
		Fsl::List<Win32MenuItem *> childItems;
	};
}

#endif

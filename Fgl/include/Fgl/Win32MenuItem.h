#ifndef __FGL_WIN32MENUITEM_H__
#define __FGL_WIN32MENUITEM_H__

#include <Windows.h>

#include "MenuItem.h"

namespace Fgl
{
	class Win32MenuItem : public MenuItem
	{
	public:
		Win32MenuItem(const Fsl::String& text);
		virtual ~Win32MenuItem();

		int GetId() const;

	private:
		static Fsl::List<int> ids;

		int id;
	};
}

#endif

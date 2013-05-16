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

		virtual void SetChecked(bool checked);
		virtual bool GetChecked() const;
		virtual void SetToggleEnabled(bool toggleEnabled);
		virtual bool GetToggleEnabled() const;

		int GetId() const;

	private:
		static Fsl::List<int> ids;

		int id;
		bool checked;
		bool toggleEnabled;
	};
}

#endif

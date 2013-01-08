#ifndef __FGL_MENU_H__
#define __FGL_MENU_H__

#include "MenuChild.h"
#include "MenuItem.h"

#include <Fsl.h>

namespace Fgl
{
	class Menu : public MenuChild
	{
	public:
		static Menu *Create(const Fsl::String& text = "");

		virtual ~Menu();

		virtual void AddChild(Menu *child) = 0;
		virtual void AddChild(MenuItem *child) = 0;
		virtual void AddSeparator() = 0;

	protected:
		Menu(const Fsl::String& text);
	};
}

#endif

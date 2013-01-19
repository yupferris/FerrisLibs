#ifndef __FGL_MENUITEM_H__
#define __FGL_MENUITEM_H__

#include <Fsl.h>

#include "MenuChild.h"

namespace Fgl
{
	class MenuItem : public MenuChild
	{
	public:
		static MenuItem *Create(const Fsl::String& text);

		virtual ~MenuItem();

		Fsl::Event Click;

	protected:
		MenuItem(const Fsl::String& text);
	};
}

#endif

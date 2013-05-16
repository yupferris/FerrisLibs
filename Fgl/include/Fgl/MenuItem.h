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

		virtual void SetChecked(bool checked) = 0;
		virtual bool GetChecked() const = 0;
		virtual void SetToggleEnabled(bool toggleEnabled) = 0;
		virtual bool GetToggleEnabled() const = 0;

		Fsl::Event Click;
		Fsl::Event CheckedChanged;

	protected:
		MenuItem(const Fsl::String& text);
	};
}

#endif

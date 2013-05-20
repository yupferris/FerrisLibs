#ifndef __FGL_PANEL_H__
#define __FGL_PANEL_H__

#include <Fsl.h>

#include "Widget.h"
#include "IWidgetParent.h"

namespace Fgl
{
	class Panel : public Widget, public IWidgetParent
	{
	public:
		virtual ~Panel();

		virtual void AddChild(Widget *child);

	protected:
		Fsl::List<Widget *> children;
	};
}

#endif

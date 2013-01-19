#ifndef __FGL_IWIDGETPARENT_H__
#define __FGL_IWIDGETPARENT_H__

#include <Fsl.h>

namespace Fgl
{
	class Widget;

	class IWidgetParent
	{
	public:
		virtual void AddChild(Widget *child) = 0;
		virtual void RemoveChild(Widget *child) = 0;
		virtual const Fsl::List<Widget *>& GetChildren() const = 0;
	};
};

#endif

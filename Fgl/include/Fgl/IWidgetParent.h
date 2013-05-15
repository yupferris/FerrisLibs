#ifndef __FGL_IWIDGETPARENT_H__
#define __FGL_IWIDGETPARENT_H__

#include <Fsl.h>

namespace Fgl
{
	class IWidgetParent
	{
	public:
		virtual void *GetNativeHandle() const = 0;
	};
};

#endif

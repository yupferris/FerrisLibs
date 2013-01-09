#ifndef __FGL_VIEWPORT_H__
#define __FGL_VIEWPORT_H__

#include "Widget.h"

namespace Fgl
{
	class Viewport : public Widget
	{
	public:
		void *GetNativeHandle() const;
	};
}

#endif

#ifndef __FGL_VIEWPORT_H__
#define __FGL_VIEWPORT_H__

#include "Widget.h"

namespace Fgl
{
	class Viewport : public Widget
	{
	public:
		static Viewport *Create();

		virtual ~Viewport();

		virtual void *GetNativeHandle() const = 0;
	};
}

#endif

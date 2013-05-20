#ifndef __FGL_BUTTON_H__
#define __FGL_BUTTON_H__

#include <Fsl.h>

#include "Widget.h"

namespace Fgl
{
	class Button : public Widget
	{
	public:
		static Button *Create();

		virtual ~Button();

		Fsl::Event Click;
	};
}

#endif

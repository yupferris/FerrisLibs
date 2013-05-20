#ifndef __FGL_BUTTON_H__
#define __FGL_BUTTON_H__

#include <Fsl.h>

#include "Widget.h"

namespace Fgl
{
	class Button : public Widget
	{
	public:
		static Button *Create(const Fsl::String& text, int x = 0, int y = 0, int desiredWidth = 75, int desiredHeight = 25);

		virtual ~Button();

		virtual Fsl::String GetText() const;
		virtual void SetText(const Fsl::String& text);

		Fsl::Event Click;

	protected:
		Button(const Fsl::String& text, int x, int y, int desiredWidth, int desiredHeight);

	private:
		Fsl::String text;
	};
}

#endif

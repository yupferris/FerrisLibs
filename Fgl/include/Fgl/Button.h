#ifndef __FGL_BUTTON_H__
#define __FGL_BUTTON_H__

#include <Fsl.h>

#include "Widget.h"

namespace Fgl
{
	class Button : public Widget
	{
	public:
		static Button *Create(const Fsl::String& text);

		virtual ~Button();

		virtual Fsl::String GetText() const;
		virtual void SetText(const Fsl::String& text);

		Fsl::Event Click;

	protected:
		Button(const Fsl::String& text);

	private:
		Fsl::String text;
	};
}

#endif

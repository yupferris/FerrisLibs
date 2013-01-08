#ifndef __FGL_MENUCHILD_H__
#define __FGL_MENUCHILD_H__

#include <Fsl.h>

namespace Fgl
{
	class MenuChild
	{
	public:
		virtual ~MenuChild();

		virtual Fsl::String GetText() const;
		virtual void SetText(const Fsl::String& text);

	protected:
		MenuChild(const Fsl::String& text);

		Fsl::String text;
	};
}

#endif

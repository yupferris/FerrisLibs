#include <Fgl/MenuItem.h>

using namespace Fsl;

namespace Fgl
{
	MenuItem::~MenuItem()
	{
	}

	void MenuItem::OnClick()
	{
		for (int i = 0; i < Click.Count(); i++) Click[i]();
	}

	MenuItem::MenuItem(const String& text)
		: MenuChild(text)
	{
	}
}

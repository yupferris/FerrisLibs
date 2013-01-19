#include <Fgl/MenuItem.h>

using namespace Fsl;

namespace Fgl
{
	MenuItem::~MenuItem()
	{
	}

	MenuItem::MenuItem(const String& text)
		: MenuChild(text)
	{
	}
}

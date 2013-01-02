#include <Fgl/Win32MenuItem.h>

using namespace Fsl;

namespace Fgl
{
	MenuItem *MenuItem::Create(const String& text)
	{
		return new Win32MenuItem(text);
	}

	List<int> Win32MenuItem::ids;

	Win32MenuItem::Win32MenuItem(const String& text)
		: MenuItem(text)
	{
		for (int i = 0; ; i++)
		{
			if (!ids.Contains(i))
			{
				id = i;
				ids.Add(i);
				break;
			}

			if (i == 0xffff) throw FSL_EXCEPTION("Could not create new menu item");
		}
	}

	Win32MenuItem::~Win32MenuItem()
	{
		ids.Remove(id);
	}

	int Win32MenuItem::GetId() const
	{
		return id;
	}
}

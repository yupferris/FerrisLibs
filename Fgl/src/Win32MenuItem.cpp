#include <Fgl/Win32MenuItem.h>
#include <Fgl/Win32Controls.h>

using namespace Fsl;

namespace Fgl
{
	MenuItem *MenuItem::Create(const String& text)
	{
		return new Win32MenuItem(text);
	}

	Win32MenuItem::Win32MenuItem(const String& text)
		: MenuItem(text)
	{
		id = Win32Controls::GetNewId();
		checked = false;
		toggleEnabled = false;
		Click += [&]
			{
				if (toggleEnabled) SetChecked(!GetChecked());
			};
	}

	Win32MenuItem::~Win32MenuItem()
	{
		Win32Controls::RemoveId(id);
	}

	void Win32MenuItem::SetChecked(bool checked)
	{
		this->checked = checked;
		CheckedChanged();
	}

	bool Win32MenuItem::GetChecked() const
	{
		return checked;
	}

	void Win32MenuItem::SetToggleEnabled(bool toggleEnabled)
	{
		this->toggleEnabled = toggleEnabled;
	}

	bool Win32MenuItem::GetToggleEnabled() const
	{
		return toggleEnabled;
	}

	int Win32MenuItem::GetId() const
	{
		return id;
	}
}

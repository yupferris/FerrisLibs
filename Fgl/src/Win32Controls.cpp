#include <Fgl/Win32Controls.h>

using namespace Fsl;

#include <CommCtrl.h>

#pragma comment(linker, "\"/manifestdependency:type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

namespace Fgl
{
	bool Win32Controls::initialized = false;
	List<int> Win32Controls::ids;

	void Win32Controls::Init()
	{
		if (!initialized)
		{
			INITCOMMONCONTROLSEX icc = { sizeof(icc), ICC_STANDARD_CLASSES };
			InitCommonControlsEx(&icc);
			initialized = true;
		}
	}

	int Win32Controls::GetNewId()
	{
		for (int i = 0; i <= 0xffff; i++)
		{
			if (!ids.Contains(i))
			{
				ids.Add(i);
				return i;
			}
		}
		throw FSL_EXCEPTION("Could not create new control ID");
	}

	void Win32Controls::RemoveId(int id)
	{
		ids.Remove(id);
	}

	void Win32Controls::SetDefaultFont(HWND parentHandle, int id)
	{
		SendDlgItemMessage(parentHandle, id, WM_SETFONT, (WPARAM)GetStockObject(DEFAULT_GUI_FONT), MAKELPARAM(TRUE, 0));
	}
}

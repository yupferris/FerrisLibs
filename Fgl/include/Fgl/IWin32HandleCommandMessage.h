#ifndef __FGL_IWIN32HANDLECOMMANDMESSAGE_H__
#define __FGL_IWIN32HANDLECOMMANDMESSAGE_H__

#include <Windows.h>

namespace Fgl
{
	class IWin32HandleCommandMessage
	{
	public:
		virtual void HandleCommandMessage(LPARAM wParam) = 0;
	};
}

#endif

#include <Fel/VideoDriverFactory.h>

#include <Fel/Win32GLVideoDriver.h>

namespace Fel
{
	IVideoDriver *VideoDriverFactory::CreateDefault()
	{
		return new Win32GLVideoDriver();
	}
}

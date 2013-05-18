#ifndef __FEL_VIDEODRIVERFACTORY_H__
#define __FEL_VIDEODRIVERFACTORY_H__

#include "IVideoDriver.h"

namespace Fel
{
	class VideoDriverFactory
	{
	public:
		static IVideoDriver *CreateDefault();
	};
}

#endif

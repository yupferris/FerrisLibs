#ifndef __FEL_AUDIODRIVERFACTORY_H__
#define __FEL_AUDIODRIVERFACTORY_H__

#include "IAudioDriver.h"

namespace Fel
{
	class AudioDriverFactory
	{
	public:
		static IAudioDriver *CreateDefault();
	};
}

#endif

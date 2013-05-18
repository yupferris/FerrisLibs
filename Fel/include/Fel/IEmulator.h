#ifndef __FEL_IEMULATOR_H__
#define __FEL_IEMULATOR_H__

#include "IVideoDriver.h"
#include "IAudioDriver.h"

namespace Fel
{
	class IEmulator
	{
	public:
		virtual void Reset() = 0;
		virtual void Update() = 0;

		virtual int GetOutputWidth() const = 0;
		virtual int GetOutputHeight() const = 0;

		virtual void SetVideoDriver(IVideoDriver *videoDriver) = 0;
		virtual void SetAudioDriver(IAudioDriver *audioDriver) = 0;
	};
}

#endif

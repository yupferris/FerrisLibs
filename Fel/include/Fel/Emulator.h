#ifndef __EMULATOR_H__
#define __EMULATOR_H__

#include "VideoModule.h"

namespace Fel
{
	class Emulator
	{
	public:
		virtual void Reset() = 0;
		virtual void Update() = 0;

		virtual int GetOutputWidth() const = 0;
		virtual int GetOutputHeight() const = 0;

		virtual void SetVideoModule(VideoModule *videoModule) = 0;
	};
}

#endif

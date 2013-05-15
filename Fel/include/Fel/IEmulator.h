#ifndef __FEL_IEMULATOR_H__
#define __FEL_IEMULATOR_H__

#include "IVideoModule.h"

namespace Fel
{
	class IEmulator
	{
	public:
		virtual void Reset() = 0;
		virtual void Update() = 0;

		virtual int GetOutputWidth() const = 0;
		virtual int GetOutputHeight() const = 0;

		virtual void SetVideoModule(IVideoModule *videoModule) = 0;
	};
}

#endif

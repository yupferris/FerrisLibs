#ifndef __FEL_IEMULATOR32_H__
#define __FEL_IEMULATOR32_H__

#include "IEmulator16.h"

namespace Fel
{
	class IEmulator32 : public IEmulator16
	{
	public:
		virtual unsigned short ReadWord(unsigned int address) = 0;
		virtual unsigned int ReadDword(unsigned int address) = 0;
	};
}

#endif

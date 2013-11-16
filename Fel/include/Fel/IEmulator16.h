#ifndef __FEL_IEMULATOR16_H__
#define __FEL_IEMULATOR16_H__

#include "IEmulator8.h"

namespace Fel
{
	class IEmulator16 : public IEmulator8
	{
	public:
		virtual void WriteWord(unsigned int address, unsigned short value) = 0;
		virtual void WriteDword(unsigned int address, unsigned int value) = 0;
	};
}

#endif

#ifndef __FEL_IEMULATOR8_H__
#define __FEL_IEMULATOR8_H__

#include "IEmulator.h"

namespace Fel
{
	class IEmulator8 : public IEmulator
	{
	public:
		virtual unsigned char ReadByte(unsigned int address) = 0;
		virtual void WriteByte(unsigned int address, unsigned char value) = 0;
	};
}

#endif

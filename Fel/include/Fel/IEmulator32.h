#ifndef __FEL_IEMULATOR32_H__
#define __FEL_IEMULATOR32_H__

#include "IEmulator8.h"

namespace Fel
{
	class IEmulator32 : public IEmulator8
	{
	public:
		virtual unsigned short ReadWord(unsigned int address) = 0;
		virtual unsigned int ReadDword(unsigned int address) = 0;
		virtual void WriteWord(unsigned int address, unsigned short value) = 0;
		virtual void WriteDword(unsigned int address, unsigned int value) = 0;
	};
}

#endif

#ifndef __FEL_EMULATOR32_H__
#define __FEL_EMULATOR32_H__

#include "Emulator.h"

namespace Fel
{
	class Emulator32 : public Emulator
	{
	public:
		virtual unsigned char ReadByte(unsigned int address) = 0;
		virtual unsigned short ReadWord(unsigned int address) = 0;
		virtual unsigned int ReadDword(unsigned int address) = 0;
		virtual void WriteByte(unsigned int address, unsigned char value) = 0;
		virtual void WriteWord(unsigned int address, unsigned short value) = 0;
		virtual void WriteDword(unsigned int address, unsigned int value) = 0;
	};
}

#endif

#ifndef __FSL_BINARYWRITER_H__
#define __FSL_BINARYWRITER_H__

#include <Fsl/Stream.h>

namespace Fsl
{
	class BinaryWriter
	{
	public:
		BinaryWriter(Stream *stream);

		void WriteByte(unsigned char value);
		void WriteInt16(short value, bool littleEndian = true);
		void WriteUInt16(unsigned short value, bool littleEndian = true);
		void WriteInt32(int value, bool littleEndian = true);
		void WriteUInt32(unsigned int value, bool littleEndian = true);
		void WriteInt64(long long value, bool littleEndian = true);
		void WriteUInt64(unsigned long long value, bool littleEndian = true);

		void WriteSingle(float value, bool littleEndian = true);
		void WriteDouble(double value, bool littleEndian = true);

	private:
		Stream *stream;
	};
}

#endif

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
		void WriteInt16(short value);
		void WriteUInt16(unsigned short value);
		void WriteInt32(int value);
		void WriteUInt32(unsigned int value);
		void WriteInt64(long long value);
		void WriteUInt64(unsigned long long value);

		void WriteSingle(float value);
		void WriteDouble(double value);

	private:
		Stream *stream;
	};
}

#endif

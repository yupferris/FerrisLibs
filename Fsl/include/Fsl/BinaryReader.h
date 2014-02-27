#ifndef __FSL_BINARYREADER_H__
#define __FSL_BINARYREADER_H__

#include <Fsl/Stream.h>

namespace Fsl
{
	class BinaryReader
	{
	public:
		BinaryReader(Stream *stream);

		unsigned char ReadByte();
		short ReadInt16(bool littleEndian = true);
		unsigned short ReadUInt16(bool littleEndian = true);
		int ReadInt32(bool littleEndian = true);
		unsigned int ReadUInt32(bool littleEndian = true);
		long long ReadInt64(bool littleEndian = true);
		unsigned long long ReadUInt64(bool littleEndian = true);

		float ReadSingle(bool littleEndian = true);
		double ReadDouble(bool littleEndian = true);

	private:
		Stream *stream;
	};
}

#endif

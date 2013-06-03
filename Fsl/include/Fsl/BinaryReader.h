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
		short ReadInt16();
		unsigned short ReadUInt16();
		int ReadInt32();
		unsigned int ReadUInt32();
		long long ReadInt64();
		unsigned long long ReadUInt64();

		float ReadSingle();
		double ReadDouble();

	private:
		Stream *stream;
	};
}

#endif

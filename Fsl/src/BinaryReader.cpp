#include <Fsl/BinaryReader.h>

namespace Fsl
{
	BinaryReader::BinaryReader(Stream *stream)
	{
		this->stream = stream;
	}

	unsigned char BinaryReader::ReadByte()
	{
		return stream->ReadByte();
	}

	short BinaryReader::ReadInt16(bool littleEndian)
	{
		unsigned char data[2];
		for (int i = 0; i < 2; i++)
			data[littleEndian ? i : 1 - i] = ReadByte();
		return *(short *)data;
	}

	unsigned short BinaryReader::ReadUInt16(bool littleEndian)
	{
		unsigned char data[2];
		for (int i = 0; i < 2; i++)
			data[littleEndian ? i : 1 - i] = ReadByte();
		return *(unsigned short *)data;
	}

	int BinaryReader::ReadInt32(bool littleEndian)
	{
		unsigned char data[4];
		for (int i = 0; i < 4; i++)
			data[littleEndian ? i : 3 - i] = ReadByte();
		return *(int *)data;
	}

	unsigned int BinaryReader::ReadUInt32(bool littleEndian)
	{
		unsigned char data[4];
		for (int i = 0; i < 4; i++)
			data[littleEndian ? i : 3 - i] = ReadByte();
		return *(unsigned int *)data;
	}

	long long BinaryReader::ReadInt64(bool littleEndian)
	{
		unsigned char data[8];
		for (int i = 0; i < 8; i++)
			data[littleEndian ? i : 7 - i] = ReadByte();
		return *(long long *)data;
	}

	unsigned long long BinaryReader::ReadUInt64(bool littleEndian)
	{
		unsigned char data[8];
		for (int i = 0; i < 8; i++)
			data[littleEndian ? i : 7 - i] = ReadByte();
		return *(unsigned long long *)data;
	}

	float BinaryReader::ReadSingle(bool littleEndian)
	{
		unsigned char data[4];
		for (int i = 0; i < 4; i++)
			data[littleEndian ? i : 3 - i] = ReadByte();
		return *(float *)data;
	}
}

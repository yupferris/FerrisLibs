#include <Fsl/BinaryWriter.h>

namespace Fsl
{
	BinaryWriter::BinaryWriter(Stream *stream)
	{
		this->stream = stream;
	}

	void BinaryWriter::WriteByte(unsigned char value)
	{
		stream->WriteByte(value);
	}

	void BinaryWriter::WriteInt16(short value)
	{
		stream->Write((const unsigned char *)&value, 0, 2);
	}

	void BinaryWriter::WriteUInt16(unsigned short value)
	{
		stream->Write((const unsigned char *)&value, 0, 2);
	}

	void BinaryWriter::WriteInt32(int value)
	{
		stream->Write((const unsigned char *)&value, 0, 4);
	}

	void BinaryWriter::WriteUInt32(unsigned int value)
	{
		stream->Write((const unsigned char *)&value, 0, 4);
	}

	void BinaryWriter::WriteInt64(long long value)
	{
		stream->Write((const unsigned char *)&value, 0, 8);
	}

	void BinaryWriter::WriteUInt64(unsigned long long value)
	{
		stream->Write((const unsigned char *)&value, 0, 8);
	}

	void BinaryWriter::WriteSingle(float value)
	{
		stream->Write((const unsigned char *)&value, 0, 4);
	}

	void BinaryWriter::WriteDouble(double value)
	{
		stream->Write((const unsigned char *)&value, 0, 8);
	}
}

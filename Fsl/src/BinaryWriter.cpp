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

	void BinaryWriter::WriteInt16(short value, bool littleEndian)
	{
		if (littleEndian)
		{
			stream->Write((const unsigned char *)&value, 0, 2);
		}
		else
		{
			for (int i = 0; i < 2; i++)
				stream->WriteByte(((const unsigned char *)&value)[1 - i]);
		}
	}

	void BinaryWriter::WriteUInt16(unsigned short value, bool littleEndian)
	{
		if (littleEndian)
		{
			stream->Write((const unsigned char *)&value, 0, 2);
		}
		else
		{
			for (int i = 0; i < 2; i++)
				stream->WriteByte(((const unsigned char *)&value)[1 - i]);
		}
	}

	void BinaryWriter::WriteInt32(int value, bool littleEndian)
	{
		if (littleEndian)
		{
			stream->Write((const unsigned char *)&value, 0, 4);
		}
		else
		{
			for (int i = 0; i < 4; i++)
				stream->WriteByte(((const unsigned char *)&value)[3 - i]);
		}
	}

	void BinaryWriter::WriteUInt32(unsigned int value, bool littleEndian)
	{
		if (littleEndian)
		{
			stream->Write((const unsigned char *)&value, 0, 4);
		}
		else
		{
			for (int i = 0; i < 4; i++)
				stream->WriteByte(((const unsigned char *)&value)[3 - i]);
		}
	}

	void BinaryWriter::WriteInt64(long long value, bool littleEndian)
	{
		if (littleEndian)
		{
			stream->Write((const unsigned char *)&value, 0, 8);
		}
		else
		{
			for (int i = 0; i < 8; i++)
				stream->WriteByte(((const unsigned char *)&value)[7 - i]);
		}
	}

	void BinaryWriter::WriteUInt64(unsigned long long value, bool littleEndian)
	{
		if (littleEndian)
		{
			stream->Write((const unsigned char *)&value, 0, 8);
		}
		else
		{
			for (int i = 0; i < 8; i++)
				stream->WriteByte(((const unsigned char *)&value)[7 - i]);
		}
	}

	void BinaryWriter::WriteSingle(float value, bool littleEndian)
	{
		if (littleEndian)
		{
			stream->Write((const unsigned char *)&value, 0, 4);
		}
		else
		{
			for (int i = 0; i < 4; i++)
				stream->WriteByte(((const unsigned char *)&value)[3 - i]);
		}
	}

	void BinaryWriter::WriteDouble(double value, bool littleEndian)
	{
		if (littleEndian)
		{
			stream->Write((const unsigned char *)&value, 0, 8);
		}
		else
		{
			for (int i = 0; i < 8; i++)
				stream->WriteByte(((const unsigned char *)&value)[7 - i]);
		}
	}
}

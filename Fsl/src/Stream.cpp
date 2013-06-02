#include <Fsl/Stream.h>
#include <Fsl/NotSupportedException.h>

namespace Fsl
{
	Stream::~Stream()
	{
	}

	int Stream::Length()
	{
		throw FSL_NOTSUPPORTEDEXCEPTION;
	}

	int Stream::GetPosition()
	{
		throw FSL_NOTSUPPORTEDEXCEPTION;
	}

	void Stream::SetPosition(int position)
	{
		throw FSL_NOTSUPPORTEDEXCEPTION;
	}

	unsigned char Stream::ReadByte()
	{
		throw FSL_NOTSUPPORTEDEXCEPTION;
	}

	int Stream::Read(unsigned char *buffer, int offset, int count)
	{
		int i = offset;
		for (; i < count && GetPosition() < Length(); i++) buffer[i] = ReadByte();
		return i - offset;
	}

	void Stream::WriteByte(unsigned char byte)
	{
		throw FSL_NOTSUPPORTEDEXCEPTION;
	}

	void Stream::Write(const unsigned char *buffer, int offset, int count)
	{
		for (int i = 0; i < count; i++) WriteByte(buffer[offset + i]);
	}

	void Stream::CopyTo(Stream *dest)
	{
		while (GetPosition() < Length()) dest->WriteByte(ReadByte());
	}
}

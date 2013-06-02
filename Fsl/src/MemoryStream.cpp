#include <Fsl/MemoryStream.h>
#include <Fsl/Exception.h>
#include <Fsl/EndOfStreamException.h>

namespace Fsl
{
	MemoryStream::MemoryStream()
	{
		const int initialSize = 4096;
		size = initialSize;
		used = position = 0;
		buffer = new unsigned char[initialSize];
	}

	MemoryStream::~MemoryStream()
	{
		delete [] buffer;
	}

	bool MemoryStream::CanRead() const
	{
		return true;
	}

	bool MemoryStream::CanWrite() const
	{
		return true;
	}

	int MemoryStream::Length()
	{
		return used;
	}

	int MemoryStream::GetPosition()
	{
		return position;
	}

	void MemoryStream::SetPosition(int position)
	{
		if (position < 0) throw FSL_EXCEPTION("Position must be positive");
		this->position = position;
	}

	unsigned char MemoryStream::ReadByte()
	{
		if (position >= Length()) throw FSL_ENDOFSTREAMEXCEPTION;
		return buffer[position++];
	}

	void MemoryStream::WriteByte(unsigned char byte)
	{
		used = position + 1;
		ensureCapacity();
		buffer[position++] = byte;
	}

	void MemoryStream::ensureCapacity()
	{
		if (size < used)
		{
			int newSize = size;
			while (newSize < used + 1) newSize *= 2;
			auto newBuffer = new unsigned char[newSize];
			for (int i = 0; i < size; i++) newBuffer[i] = buffer[i];
			delete buffer;
			buffer = newBuffer;
		}
	}
}

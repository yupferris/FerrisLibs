#include <Fsl/BitReader.h>
#include <Fsl/Exception.h>

namespace Fsl
{
	BitReader::BitReader(Stream *inputStream, BitOrder bitOrder)
	{
		this->inputStream = inputStream;
		this->bitOrder = bitOrder;
		buffer = 0;
		bitCount = -1;
	}

	BitOrder BitReader::GetBitOrder() const
	{
		return bitOrder;
	}

	void BitReader::SetBitOrder(BitOrder bitOrder)
	{
		if (!IsOnByteBoundary()) throw FSL_EXCEPTION("Bit order can only be set on byte boundaries");
		this->bitOrder = bitOrder;
	}

	bool BitReader::IsOnByteBoundary()
	{
		return bitCount < 0 || bitCount >= 8;
	}

	bool BitReader::ReadBit()
	{
		if (IsOnByteBoundary())
		{
			buffer = inputStream->ReadByte();
			bitCount = 0;
		}
		int shift = bitOrder == BitOrder::LeastSignificantToMostSignificant ? bitCount : 7 - bitCount;
		bitCount++;
		return ((buffer >> shift) & 1) != 0;
	}

	unsigned int BitReader::ReadBits(int count)
	{
		if (count < 0) throw FSL_EXCEPTION("count must be positive");
		if (count > 32) throw FSL_EXCEPTION("count must not be greater than 32");
		unsigned int ret = 0;
		for (int i = 0; i < count; i++)
		{
			ret <<= 1;
			ret |= ReadBit() ? 1 : 0;
		}
		return ret;
	}

	int BitReader::ReadToByteBoundary()
	{
		int bitsRead = 0;
		for (; !IsOnByteBoundary(); bitsRead++) ReadBit();
		return bitsRead;
	}
}

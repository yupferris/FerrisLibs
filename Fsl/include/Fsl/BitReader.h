#ifndef __FSL_BITREADER_H__
#define __FSL_BITREADER_H__

#include "Stream.h"
#include "BitOrder.h"

namespace Fsl
{
	class BitReader
	{
	public:
		BitReader(Stream *inputStream, BitOrder bitOrder = BitOrder::LeastSignificantToMostSignificant);

		BitOrder GetBitOrder() const;
		void SetBitOrder(BitOrder bitOrder);

		bool IsOnByteBoundary();

		bool ReadBit();
		unsigned int ReadBits(int count);
		int ReadToByteBoundary();

	private:
		Stream *inputStream;
		BitOrder bitOrder;
		unsigned char buffer;
		int bitCount;
	};
}

#endif

#ifndef __FSL_MEMORYSTREAM_H__
#define __FSL_MEMORYSTREAM_H__

#include <Fsl/Stream.h>

namespace Fsl
{
	class MemoryStream : public Stream
	{
	public:
		MemoryStream();
		virtual ~MemoryStream();

		virtual bool CanRead() const;
		virtual bool CanWrite() const;

		virtual int Length();

		virtual int GetPosition();
		virtual void SetPosition(int position);

		virtual unsigned char ReadByte();

		virtual void WriteByte(unsigned char byte);

	private:
		void ensureCapacity();

		int size, used;
		int position;
		unsigned char *buffer;
	};
}

#endif

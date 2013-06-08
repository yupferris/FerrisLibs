#ifndef __FSL_STREAM_H__
#define __FSL_STREAM_H__

namespace Fsl
{
	class Stream
	{
	public:
		virtual ~Stream();

		virtual bool CanRead() const = 0;
		virtual bool CanWrite() const = 0;

		virtual int Length();

		virtual int GetPosition();
		virtual void SetPosition(int position);

		virtual unsigned char ReadByte();
		virtual int Read(unsigned char *buffer, int offset, int count);

		virtual void WriteByte(unsigned char byte);
		virtual void Write(const unsigned char *buffer, int offset, int count);

		void CopyTo(Stream *dest, int bufferSize = 4096);
	};
}

#endif

#ifndef __FSL_FILESTREAM_H__
#define __FSL_FILESTREAM_H__

#include "Stream.h"
#include "String.h"

namespace Fsl
{
	class FileStream : public Stream
	{
	public:
		enum class FileMode
		{
			Open,
		};

		FileStream(const String& fileName, FileMode fileMode);
		virtual ~FileStream();

		virtual bool CanRead() const;
		virtual bool CanWrite() const;

		virtual int Length();

		virtual int GetPosition();
		virtual void SetPosition(int position);

		virtual unsigned char ReadByte();
		virtual int Read(unsigned char *buffer, int offset, int count);

		virtual void WriteByte(unsigned char byte);
		virtual void Write(const unsigned char *buffer, int offset, int count);

	private:
		Stream *internalStream;
	};
}

#endif

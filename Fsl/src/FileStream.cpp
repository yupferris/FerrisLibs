#include <Fsl/FileStream.h>
#include <Fsl/EndOfStreamException.h>

#include <fstream>
using namespace std;

namespace Fsl
{
	class ReadOnlyFileStream : public Stream
	{
	public:
		ReadOnlyFileStream(const String& fileName)
		{
			internalStream.open(fileName.GetData(), ios::binary | ios::ate);
			if (internalStream.fail()) throw FSL_EXCEPTION("Could not open file");
			length = (int)internalStream.tellg();
			internalStream.seekg(0);
		}

		virtual ~ReadOnlyFileStream()
		{
			internalStream.close();
		}

		virtual bool CanRead() const
		{
			return true;
		}

		virtual bool CanWrite() const
		{
			return false;
		}

		virtual int Length()
		{
			return length;
		}

		virtual int GetPosition()
		{
			return (int)internalStream.tellg();
		}

		virtual void SetPosition(int position)
		{
			if (position < 0) throw FSL_EXCEPTION("Position must be positive");
			if (position > Length()) throw FSL_EXCEPTION("Position out of bounds");
			internalStream.seekg(position);
		}

		virtual unsigned char ReadByte()
		{
			if (internalStream.eof()) throw FSL_ENDOFSTREAMEXCEPTION;
			return internalStream.get();
		}

	private:
		std::ifstream internalStream;
		int length;
	};

	class WriteOnlyFileStream : public Stream
	{
	public:
		WriteOnlyFileStream(const String& fileName)
		{
			internalStream.open(fileName.GetData(), ios::binary);
			if (internalStream.fail()) throw FSL_EXCEPTION("Could not open file");
		}

		virtual ~WriteOnlyFileStream()
		{
			internalStream.close();
		}

		virtual bool CanRead() const
		{
			return false;
		}

		virtual bool CanWrite() const
		{
			return true;
		}

		virtual int Length()
		{
			return GetPosition();
		}

		virtual int GetPosition()
		{
			return (int)internalStream.tellp();
		}

		virtual void WriteByte(unsigned char byte)
		{
			internalStream.write((const char *)&byte, 1);
		}

		virtual void Write(const unsigned char *buffer, int offset, int count)
		{
			internalStream.write((const char *)buffer + offset, count);
		}

	private:
		std::ofstream internalStream;
	};

	FileStream::FileStream(const String& fileName, FileMode fileMode)
	{
		internalStream = fileMode == FileMode::Open ? (Stream *)new ReadOnlyFileStream(fileName) : new WriteOnlyFileStream(fileName);
	}

	FileStream::~FileStream()
	{
		delete internalStream;
	}

	bool FileStream::CanRead() const
	{
		return internalStream->CanRead();
	}

	bool FileStream::CanWrite() const
	{
		return internalStream->CanWrite();
	}

	int FileStream::Length()
	{
		return internalStream->Length();
	}

	int FileStream::GetPosition()
	{
		return internalStream->GetPosition();
	}

	void FileStream::SetPosition(int position)
	{
		internalStream->SetPosition(position);
	}

	unsigned char FileStream::ReadByte()
	{
		return internalStream->ReadByte();
	}

	int FileStream::Read(unsigned char *buffer, int offset, int count)
	{
		return internalStream->Read(buffer, offset, count);
	}

	void FileStream::WriteByte(unsigned char byte)
	{
		internalStream->WriteByte(byte);
	}

	void FileStream::Write(const unsigned char *buffer, int offset, int count)
	{
		internalStream->Write(buffer, offset, count);
	}
}

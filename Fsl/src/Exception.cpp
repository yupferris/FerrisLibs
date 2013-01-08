#include <Fsl/Exception.h>
#include <Fsl/String.h>

namespace Fsl
{
	Exception::Exception(const String& msg, const String& file, int line)
	{
		this->msg = msg;
		this->file = file;
		this->line = line;
	}

	String Exception::GetMsg() const
	{
		return msg;
	}

	String Exception::GetFile() const
	{
		return file;
	}

	int Exception::GetLine() const
	{
		return line;
	}
}

#include <Fsl/EndOfStreamException.h>

namespace Fsl
{
	EndOfStreamException::EndOfStreamException(const String& file, int line)
		: Exception("End of stream", file, line)
	{
	}
}

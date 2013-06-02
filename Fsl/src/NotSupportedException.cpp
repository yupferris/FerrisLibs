#include <Fsl/NotSupportedException.h>

namespace Fsl
{
	NotSupportedException::NotSupportedException(const String& file, int line)
		: Exception("Operation not supported", file, line)
	{
	}
}

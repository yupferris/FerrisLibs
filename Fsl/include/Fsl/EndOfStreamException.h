#ifndef __FSL_ENDOFSTREAMEXCEPTION_H__
#define __FSL_ENDOFSTREAMEXCEPTION_H__

#include <Fsl/Exception.h>

namespace Fsl
{
	class EndOfStreamException : public Exception
	{
	public:
		EndOfStreamException(const String& file, int line);
	};
}

#define FSL_ENDOFSTREAMEXCEPTION Fsl::EndOfStreamException(__FILE__, __LINE__)

#endif

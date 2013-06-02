#ifndef __FSL_NOTSUPPORTEDEXCEPTION_H__
#define __FSL_NOTSUPPORTEDEXCEPTION_H__

#include <Fsl/Exception.h>

namespace Fsl
{
	class NotSupportedException : public Exception
	{
	public:
		NotSupportedException(const String& file, int line);
	};
}

#define FSL_NOTSUPPORTEDEXCEPTION Fsl::NotSupportedException(__FILE__, __LINE__)

#endif

#ifndef __FSL_EXCEPTION_H__
#define __FSL_EXCEPTION_H__

#include "StringDecl.h"

namespace Fsl
{
	class Exception
	{
	public:
		Exception(const String& msg, const String& file, int line);
		String GetMsg() const;
		String GetFile() const;
		int GetLine() const;
	
	private:
		String msg, file;
		int line;
	};
}

#define FSL_EXCEPTION(x) Fsl::Exception((x), __FILE__, __LINE__)

#include "String.h"

#endif

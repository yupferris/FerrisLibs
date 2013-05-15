#ifndef __FEL_IVIDEOMODULE_H__
#define __FEL_IVIDEOMODULE_H__

namespace Fel
{
	class IVideoModule
	{
	public:
		virtual ~IVideoModule();
		virtual void SetOutput(int width, int height, const unsigned int *data) = 0;
	};
}

#endif

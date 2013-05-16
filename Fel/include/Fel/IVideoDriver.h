#ifndef __FEL_IVIDEODRIVER_H__
#define __FEL_IVIDEODRIVER_H__

namespace Fel
{
	class IVideoDriver
	{
	public:
		virtual ~IVideoDriver();

		virtual void SetOutput(int width, int height, const unsigned int *data) = 0;
	};
}

#endif

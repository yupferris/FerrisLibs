#ifndef __FEL_VIDEOMODULE_H__
#define __FEL_VIDEOMODULE_H__

namespace Fel
{
	class VideoModule
	{
	public:
		virtual ~VideoModule();
		virtual void SetOutput(int width, int height, const unsigned int *data) = 0;
	};
}

#endif

#ifndef __FEL_WIN32GLVIDEODRIVER_H__
#define __FEL_WIN32GLVIDEODRIVER_H__

#include <Fel/IVideoDriver.h>
#include <Fgl.h>
#include <Fgl/Win32Viewport.h>

#include <Windows.h>
#include <gl/GL.h>

namespace Fel
{
	class Win32GLVideoDriver : public IVideoDriver
	{
	public:
		Win32GLVideoDriver(Fgl::Viewport *viewport = nullptr);
		virtual ~Win32GLVideoDriver();

		virtual void SetViewport(Fgl::Viewport *viewport);

		virtual void SetOutput(int width, int height, const unsigned int *data);

	private:
		void createDC();
		void destroyDC();

		void createRC();

		Fgl::Win32Viewport *viewport;
		HWND outputHandle;
		HDC dc;
		HGLRC rc;

		GLuint textureHandle;
	};
}

#endif

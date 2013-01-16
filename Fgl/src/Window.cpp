#include <Fgl/Window.h>

using namespace Fsl;

namespace Fgl
{
	Window::Window(const String& title, int desiredWidth, int desiredHeight, bool fullscreen)
	{
		this->title = title;
		this->desiredWidth = width;
		this->desiredHeight = height;
		width = height = 0;
		this->fullscreen = fullscreen;
	}

	String Window::GetTitle() const
	{
		return title;
	}

	int Window::GetDesiredWidth() const
	{
		return desiredWidth;
	}

	int Window::GetDesiredHeight() const
	{
		return desiredHeight;
	}

	int Window::GetWidth() const
	{
		return width;
	}

	int Window::GetHeight() const
	{
		return height;
	}

	bool Window::GetFullscreen() const
	{
		return fullscreen;
	}

	void Window::OnResize(int width, int height)
	{
		for (int i = 0; i < Resize.Count(); i++) Resize[i](width, height);
	}

	void Window::OnKeyDown(Key key)
	{
		for (int i = 0; i < KeyDown.Count(); i++) KeyDown[i](key);
	}

	void Window::OnKeyUp(Key key)
	{
		for (int i = 0; i < KeyUp.Count(); i++) KeyUp[i](key);
	}

	void Window::OnClose()
	{
		for (int i = 0; i < Close.Count(); i++) Close[i]();
	}
}

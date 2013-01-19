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

	void Window::AddChild(Widget *child)
	{
		children.Add(child);
	}

	void Window::RemoveChild(Widget *child)
	{
		children.Remove(child);
	}

	const List<Widget *>& Window::GetChildren() const
	{
		return children;
	}
}

#include <Fgl/Window.h>

using namespace Fsl;

namespace Fgl
{
	Window::~Window()
	{
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

	void Window::SetContent(Widget *widget)
	{
		if (content) content->SetParent(nullptr);
		content = widget;
		content->SetParent(this);
	}

	Window::Window(const String& title, int desiredWidth, int desiredHeight, bool fullscreen)
	{
		this->title = title;
		this->desiredWidth = width;
		this->desiredHeight = height;
		width = height = 0;
		this->fullscreen = fullscreen;
	}
}

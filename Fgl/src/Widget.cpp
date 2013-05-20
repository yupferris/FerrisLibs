#include <Fgl/Widget.h>
#include <Fgl/IWidgetParent.h>

namespace Fgl
{
	Widget::Widget(int x, int y, int width, int height)
	{
		init(x, y, width, height);
	}

	Widget::Widget()
	{
		init(0, 0, 20, 20);
	}

	int Widget::GetDesiredX() const
	{
		return desiredX;
	}

	int Widget::GetDesiredY() const
	{
		return desiredY;
	}

	void Widget::SetDesiredPos(int desiredX, int desiredY)
	{
		this->desiredX = desiredX;
		this->desiredY = desiredY;
	}

	int Widget::GetDesiredWidth() const
	{
		return desiredWidth;
	}

	int Widget::GetDesiredHeight() const
	{
		return desiredHeight;
	}

	void Widget::SetDesiredSize(int desiredWidth, int desiredHeight)
	{
		this->desiredWidth = desiredWidth;
		this->desiredHeight = desiredHeight;
	}

	int Widget::GetX() const
	{
		return x;
	}

	int Widget::GetY() const
	{
		return y;
	}

	void Widget::SetPos(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	int Widget::GetWidth() const
	{
		return width;
	}

	int Widget::GetHeight() const
	{
		return height;
	}

	void Widget::SetSize(int width, int height)
	{
		this->width = width;
		this->height = height;
	}

	IWidgetParent *Widget::GetParent() const
	{
		return parent;
	}

	void Widget::SetParent(IWidgetParent *parent)
	{
		this->parent = parent;
	}

	void Widget::init(int x, int y, int width, int height)
	{
		desiredX = this->x = x;
		desiredY = this->y = y;
		desiredWidth = this->width = width;
		desiredHeight = this->height = height;
		parent = nullptr;
	}
}

#include <Fgl/Widget.h>
#include <Fgl/IWidgetParent.h>

namespace Fgl
{
	Widget::Widget()
	{
		desiredX = desiredY = x = y = 0;
		desiredWidth = desiredHeight = width = height = 20;
		parent = nullptr;
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
		if (parent != this->parent)
		{
			ParentChanging();
			this->parent = parent;
			ParentChanged();
		}
	}
}

#ifndef __FGL_WIDGET_H__
#define __FGL_WIDGET_H__

namespace Fgl
{
	class IWidgetParent;

	class Widget
	{
	public:
		virtual int GetDesiredX() const;
		virtual int GetDesiredY() const;
		virtual int GetDesiredWidth() const;
		virtual int GetDesiredHeight() const;
		virtual int GetX() const;
		virtual int GetY() const;
		virtual int GetWidth() const;
		virtual int GetHeight() const;

		virtual IWidgetParent *GetParent() const;
		virtual void SetParent(const IWidgetParent *parent);

	protected:
		int desiredX, desiredY;
		int desiredWidth, desiredHeight;
		int x, y;
		int width, height;

		IWidgetParent *parent;
	};
}

#endif

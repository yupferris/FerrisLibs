#ifndef __FGL_WIDGET_H__
#define __FGL_WIDGET_H__

#include <Fsl.h>

namespace Fgl
{
	class IWidgetParent;

	class Widget
	{
	public:
		Widget();

		virtual int GetDesiredX() const;
		virtual int GetDesiredY() const;
		virtual void SetDesiredPos(int desiredX, int desiredY);
		
		virtual int GetDesiredWidth() const;
		virtual int GetDesiredHeight() const;
		virtual void SetDesiredSize(int desiredWidth, int desiredHeight);
		
		virtual int GetX() const;
		virtual int GetY() const;
		virtual void SetPos(int x, int y);

		virtual int GetWidth() const;
		virtual int GetHeight() const;
		virtual void SetSize(int width, int height);

		virtual IWidgetParent *GetParent() const;
		virtual void SetParent(IWidgetParent *parent);

	private:
		int desiredX, desiredY;
		int desiredWidth, desiredHeight;
		int x, y;
		int width, height;

		IWidgetParent *parent;
	};
}

#endif

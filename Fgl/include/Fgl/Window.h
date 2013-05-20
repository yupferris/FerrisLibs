#ifndef __FGL_WINDOW_H__
#define __FGL_WINDOW_H__

#include <Fsl.h>

#include "IWidgetParent.h"
#include "Widget.h"
#include "Key.h"
#include "Menu.h"

namespace Fgl
{
	class Window : public IWidgetParent
	{
	public:
		static Window *Create(const Fsl::String& title, int desiredWidth = 800, int desiredHeight = 600, bool fullscreen = false);

		virtual ~Window();

		virtual void Update() = 0;

		virtual Fsl::String GetTitle() const;
		virtual int GetDesiredWidth() const;
		virtual int GetDesiredHeight() const;
		virtual void SetDesiredSize(int desiredWidth, int desiredHeight) = 0;
		virtual int GetWidth() const;
		virtual int GetHeight() const;
		virtual bool GetFullscreen() const;

		virtual void SetMenu(Menu *menu) = 0;

		virtual void SetContent(Widget *widget);
		virtual Widget *GetContent() const;

		Fsl::Event1<Key> KeyDown;
		Fsl::Event1<Key> KeyUp;
		Fsl::Event Closing;

	protected:
		Window(const Fsl::String& title, int width, int height, bool fullscreen);

		Fsl::String title;
		int desiredWidth, desiredHeight;
		int width, height;
		bool fullscreen;

	private:
		Widget *content;
	};
}

#endif

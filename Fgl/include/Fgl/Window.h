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

		virtual void Update() = 0;

		virtual Fsl::String GetTitle() const;
		virtual int GetDesiredWidth() const;
		virtual int GetDesiredHeight() const;
		virtual int GetWidth() const;
		virtual int GetHeight() const;
		virtual bool GetFullscreen() const;

		virtual void SetSize(int desiredWidth, int desiredHeight) = 0;

		virtual void SetMenu(Menu *menu) = 0;

		Fsl::Event2<int, int> Resize;
		Fsl::Event1<Key> KeyDown;
		Fsl::Event1<Key> KeyUp;
		Fsl::Event Closing;

		virtual void AddChild(Widget *child);
		virtual void RemoveChild(Widget *child);
		virtual const Fsl::List<Widget *>& GetChildren() const;

	protected:
		Window(const Fsl::String& title, int width, int height, bool fullscreen);

		Fsl::String title;
		int desiredWidth, desiredHeight;
		int width, height;
		bool fullscreen;

		Fsl::List<Widget *> children;
	};
}

#endif

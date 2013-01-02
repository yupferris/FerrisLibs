#ifndef __FGL_WINDOW_H__
#define __FGL_WINDOW_H__

#include <Fsl.h>

#include <functional>

#include "Key.h"
#include "Menu.h"

namespace Fgl
{
	class Window
	{
	public:
		enum class Style
		{
			Caption = 1,
			SystemMenu = 2,
			MinimizeBox = 4,

			Default = Caption | SystemMenu | MinimizeBox,
		};

		static Window *Create(const Fsl::String& title, int desiredWidth = 800, int desiredHeight = 600, bool fullscreen = false, Style style = Style::Default);

		virtual void Update() = 0;

		virtual Fsl::String GetTitle() const;
		virtual int GetDesiredWidth() const;
		virtual int GetDesiredHeight() const;
		virtual int GetWidth() const;
		virtual int GetHeight() const;
		virtual bool GetFullscreen() const;

		virtual void SetSize(int desiredWidth, int desiredHeight) = 0;

		virtual void SetMenu(Menu *menu) = 0;

		void OnResize(int width, int height);
		void OnKeyDown(Key key);
		void OnKeyUp(Key key);
		void OnClose();

		Fsl::List<std::function<void(int width, int height)>> Resize;
		Fsl::List<std::function<void(Key key)>> KeyDown;
		Fsl::List<std::function<void(Key key)>> KeyUp;
		Fsl::List<std::function<void()>> Close;

	protected:
		Window(const Fsl::String& title, int width, int height, bool fullscreen, Style style);

		Fsl::String title;
		int desiredWidth, desiredHeight;
		int width, height;
		bool fullscreen;
		Style style;
	};
}

#endif

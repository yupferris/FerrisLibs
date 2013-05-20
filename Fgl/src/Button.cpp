#include <Fgl/Button.h>

using namespace Fsl;

namespace Fgl
{
	Button::Button(const Fsl::String& text, int x, int y, int desiredWidth, int desiredHeight)
		: Widget(x, y, desiredWidth, desiredHeight)
	{
		this->text = text;
	}

	Button::~Button()
	{
	}

	String Button::GetText() const
	{
		return text;
	}

	void Button::SetText(const String& text)
	{
		this->text = text;
	}
}

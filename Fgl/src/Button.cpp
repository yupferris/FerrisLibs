#include <Fgl/Button.h>

using namespace Fsl;

namespace Fgl
{
	Button::Button(const Fsl::String& text)
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

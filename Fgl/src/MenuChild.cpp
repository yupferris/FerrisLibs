#include <Fgl/MenuChild.h>

using namespace Fsl;

namespace Fgl
{
	MenuChild::~MenuChild()
	{
	}

	MenuChild::MenuChild(const String& text)
	{
		this->text = text;
	}

	String MenuChild::GetText() const
	{
		return text;
	}

	void MenuChild::SetText(const String& text)
	{
		this->text = text;
	}
}

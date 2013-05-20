#include <Fgl/Panel.h>

using namespace Fsl;

namespace Fgl
{
	Panel::~Panel()
	{
	}

	void Panel::AddChild(Widget *child)
	{
		if (children.Contains(child)) throw FSL_EXCEPTION("Widget is already a child of this panel");
		children.Add(child);
		child->SetParent(this);
	}
}

#include <Fbl/BsonInt32Element.h>

using namespace Fsl;

namespace Fbl
{
	BsonInt32Element::BsonInt32Element(const String& name, int value)
		: BsonElement(name)
	{
		this->value = value;
	}

	BsonInt32Element::~BsonInt32Element()
	{
	}

	BsonElementType BsonInt32Element::GetType() const
	{
		return BsonElementType::Int32;
	}

	int BsonInt32Element::GetValue() const
	{
		return value;
	}
}

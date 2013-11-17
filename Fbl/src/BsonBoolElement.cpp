#include <Fbl/BsonBoolElement.h>

using namespace Fsl;

namespace Fbl
{
	BsonBoolElement::BsonBoolElement(const String& name, bool value)
		: BsonElement(name)
	{
		this->value = value;
	}

	BsonBoolElement::~BsonBoolElement()
	{
	}

	BsonElementType BsonBoolElement::GetType() const
	{
		return BsonElementType::Bool;
	}

	bool BsonBoolElement::GetValue() const
	{
		return value;
	}
}

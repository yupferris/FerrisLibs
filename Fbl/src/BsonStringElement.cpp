#include <Fbl/BsonStringElement.h>

using namespace Fsl;

namespace Fbl
{
	BsonStringElement::BsonStringElement(const String& name, const String& value)
		: BsonElement(name)
	{
		this->value = value;
	}

	BsonStringElement::~BsonStringElement()
	{
	}

	BsonElementType BsonStringElement::GetType() const
	{
		return BsonElementType::String;
	}

	const String& BsonStringElement::GetValue() const
	{
		return value;
	}
}

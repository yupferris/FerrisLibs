#include <Fbl/BsonObjectElement.h>
#include <Fbl/BsonObject.h>

using namespace Fsl;

namespace Fbl
{
	BsonObjectElement::BsonObjectElement(const String& name, BsonObject *value)
		: BsonElement(name)
	{
		this->value = value;
	}

	BsonObjectElement::~BsonObjectElement()
	{
		delete value;
	}

	BsonElementType BsonObjectElement::GetType() const
	{
		return BsonElementType::Object;
	}

	BsonObject *BsonObjectElement::GetValue() const
	{
		return value;
	}
}

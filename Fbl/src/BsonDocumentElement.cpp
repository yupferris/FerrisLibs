#include <Fbl/BsonDocumentElement.h>

using namespace Fsl;

namespace Fbl
{
	BsonDocumentElement::BsonDocumentElement(const String& name, BsonDocument *value)
		: BsonElement(name)
	{
		this->value = value;
	}

	BsonDocumentElement::~BsonDocumentElement()
	{
		delete value;
	}

	BsonElementType BsonDocumentElement::GetType() const
	{
		return BsonElementType::Document;
	}

	BsonDocument *BsonDocumentElement::GetValue() const
	{
		return value;
	}
}

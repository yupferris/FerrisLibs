#include <Fbl/BsonBinaryElement.h>

using namespace Fsl;

namespace Fbl
{
	BsonBinaryElement::BsonBinaryElement(const String& name, const List<unsigned char>& value)
		: BsonElement(name)
	{
		this->value = value;
	}

	BsonBinaryElement::~BsonBinaryElement()
	{
	}

	BsonElementType BsonBinaryElement::GetType() const
	{
		return BsonElementType::Binary;
	}

	const List<unsigned char>& BsonBinaryElement::GetValue() const
	{
		return value;
	}
}

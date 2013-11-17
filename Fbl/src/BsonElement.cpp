#include <Fbl/BsonElement.h>

using namespace Fsl;

namespace Fbl
{
	BsonElement::BsonElement(const String& name)
	{
		this->name = name;
	}

	BsonElement::~BsonElement()
	{
	}

	const String& BsonElement::GetName() const
	{
		return name;
	}
}

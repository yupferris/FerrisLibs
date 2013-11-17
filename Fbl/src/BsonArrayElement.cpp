#include <Fbl/BsonArrayElement.h>
#include <Fbl/BsonStringElement.h>
#include <Fbl/BsonDocumentElement.h>
#include <Fbl/BsonBinaryElement.h>
#include <Fbl/BsonInt32Element.h>
#include <Fbl/BsonBoolElement.h>

using namespace Fsl;

namespace Fbl
{
	BsonArrayElement::BsonArrayElement(const String& name)
		: BsonElement(name)
	{
	}

	BsonArrayElement::~BsonArrayElement()
	{
		for (int i = 0; i < elements.Count(); i++)
			delete elements[i];
	}

	BsonElementType BsonArrayElement::GetType() const
	{
		return BsonElementType::Array;
	}

	void BsonArrayElement::AddElement(BsonElement *element)
	{
		elements.Add(element);
	}

	void BsonArrayElement::AddString(const String& value)
	{
		AddElement(new BsonStringElement(elements.Count(), value));
	}

	void BsonArrayElement::AddDocument(BsonDocument *value)
	{
		AddElement(new BsonDocumentElement(elements.Count(), value));
	}

	void BsonArrayElement::AddBinary(const List<unsigned char>& value)
	{
		AddElement(new BsonBinaryElement(elements.Count(), value));
	}

	void BsonArrayElement::AddBinary(const unsigned char *data, int length)
	{
		AddElement(new BsonBinaryElement(elements.Count(), data, length));
	}

	void BsonArrayElement::AddInt32(int value)
	{
		AddElement(new BsonInt32Element(elements.Count(), value));
	}

	void BsonArrayElement::AddBool(bool value)
	{
		AddElement(new BsonBoolElement(elements.Count(), value));
	}

	List<BsonElement *> BsonArrayElement::GetElements() const
	{
		return elements;
	}
}

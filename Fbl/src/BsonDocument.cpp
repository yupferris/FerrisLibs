#include <Fbl/BsonDocument.h>
#include <Fbl/BsonStringElement.h>
#include <Fbl/BsonDocumentElement.h>
#include <Fbl/BsonBinaryElement.h>
#include <Fbl/BsonInt32Element.h>

using namespace Fsl;

namespace Fbl
{
	BsonDocument::~BsonDocument()
	{
		for (int i = 0; i < elements.Count(); i++)
			delete elements[i];
	}

	const List<BsonElement *> BsonDocument::GetElements() const
	{
		return elements;
	}

	void BsonDocument::AddString(const String& name, const String& value)
	{
		elements.Add(new BsonStringElement(name, value));
	}

	void BsonDocument::AddDocument(const String& name, BsonDocument *document)
	{
		elements.Add(new BsonDocumentElement(name, document));
	}

	void BsonDocument::AddBinary(const String& name, const Fsl::List<unsigned char>& value)
	{
		elements.Add(new BsonBinaryElement(name, value));
	}

	void BsonDocument::AddInt32(const String& name, int value)
	{
		elements.Add(new BsonInt32Element(name, value));
	}
}

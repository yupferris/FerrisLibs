#include <Fbl/BsonDocument.h>
#include <Fbl/BsonStringElement.h>
#include <Fbl/BsonDocumentElement.h>
#include <Fbl/BsonBinaryElement.h>
#include <Fbl/BsonInt32Element.h>
#include <Fbl/BsonBoolElement.h>

using namespace Fsl;

namespace Fbl
{
	BsonDocument::~BsonDocument()
	{
		auto values = elements.GetValues();
		for (int i = 0; i < values.Count(); i++)
			delete values[i];
	}

	const Dictionary<String, BsonElement *> BsonDocument::GetElements() const
	{
		return elements;
	}

	void BsonDocument::AddElement(BsonElement *element)
	{
		elements.Add(element->GetName(), element);
	}

	void BsonDocument::AddString(const String& name, const String& value)
	{
		elements.Add(name, new BsonStringElement(name, value));
	}

	void BsonDocument::AddDocument(const String& name, BsonDocument *value)
	{
		elements.Add(name, new BsonDocumentElement(name, value));
	}

	void BsonDocument::AddBinary(const String& name, const Fsl::List<unsigned char>& value)
	{
		elements.Add(name, new BsonBinaryElement(name, value));
	}

	void BsonDocument::AddBinary(const Fsl::String& name, const unsigned char *data, int length)
	{
		elements.Add(name, new BsonBinaryElement(name, data, length));
	}

	void BsonDocument::AddInt32(const String& name, int value)
	{
		elements.Add(name, new BsonInt32Element(name, value));
	}

	void BsonDocument::AddBool(const Fsl::String& name, bool value)
	{
		elements.Add(name, new BsonBoolElement(name, value));
	}

	const BsonElement *BsonDocument::TryGetElement(const Fsl::String& name) const
	{
		return elements.ContainsKey(name) ? elements[name] : nullptr;
	}

	const BsonElement *BsonDocument::GetElement(const Fsl::String& name) const
	{
		auto ret = TryGetElement(name);
		if (!ret)
			throw FSL_EXCEPTION("Document did not contain an element with the given name");
		return ret;
	}

	bool BsonDocument::TryGetElementValue(const String& name, String& value) const
	{
		auto element = tryGetElement(name, BsonElementType::String);
		if (!element)
			return false;
		value = ((BsonStringElement *)element)->GetValue();
		return true;
	}

	bool BsonDocument::TryGetElementValue(const String& name, BsonDocument *& value) const
	{
		auto element = tryGetElement(name, BsonElementType::Document);
		if (!element)
			return false;
		value = ((BsonDocumentElement *)element)->GetValue();
		return true;
	}

	bool BsonDocument::TryGetElementValue(const String& name, Fsl::List<BsonElement *>& value) const
	{
		auto element = tryGetElement(name, BsonElementType::Array);
		if (!element)
			return false;
		value = ((BsonArrayElement *)element)->GetElements();
		return true;
	}

	bool BsonDocument::TryGetElementValue(const String& name, List<unsigned char>& value) const
	{
		auto element = tryGetElement(name, BsonElementType::Binary);
		if (!element)
			return false;
		value = ((BsonBinaryElement *)element)->GetValue();
		return true;
	}

	bool BsonDocument::TryGetElementValue(const String& name, int& value) const
	{
		auto element = tryGetElement(name, BsonElementType::Int32);
		if (!element)
			return false;
		value = ((BsonInt32Element *)element)->GetValue();
		return true;
	}

	bool BsonDocument::TryGetElementValue(const String& name, bool& value) const
	{
		auto element = tryGetElement(name, BsonElementType::Bool);
		if (!element)
			return false;
		value = ((BsonBoolElement *)element)->GetValue();
		return true;
	}

	const String& BsonDocument::GetStringValue(const String& name) const
	{
		auto element = getElement(name, BsonElementType::String);
		return ((BsonStringElement *)element)->GetValue();
	}

	BsonDocument *BsonDocument::GetDocumentValue(const String& name) const
	{
		auto element = getElement(name, BsonElementType::Document);
		return ((BsonDocumentElement *)element)->GetValue();
	}

	const List<BsonElement *> BsonDocument::GetArrayValue(const String& name) const
	{
		auto element = getElement(name, BsonElementType::Array);
		return ((BsonArrayElement *)element)->GetElements();
	}

	const List<unsigned char>& BsonDocument::GetBinaryValue(const String& name) const
	{
		auto element = getElement(name, BsonElementType::Binary);
		return ((BsonBinaryElement *)element)->GetValue();
	}

	int BsonDocument::GetInt32Value(const String& name) const
	{
		auto element = getElement(name, BsonElementType::Int32);
		return ((BsonInt32Element *)element)->GetValue();
	}

	bool BsonDocument::GetBoolValue(const String& name) const
	{
		auto element = getElement(name, BsonElementType::Bool);
		return ((BsonBoolElement *)element)->GetValue();
	}

	const BsonElement *BsonDocument::tryGetElement(const Fsl::String& name, BsonElementType type) const
	{
		auto ret = TryGetElement(name);
		if (!ret)
			return nullptr;
		if (ret->GetType() != type)
			return nullptr;
		return ret;
	}

	const BsonElement *BsonDocument::getElement(const Fsl::String& name, BsonElementType type) const
	{
		auto ret = GetElement(name);
		if (ret->GetType() != type)
			throw FSL_EXCEPTION("Element type does not match the given type");
		return ret;
	}
}

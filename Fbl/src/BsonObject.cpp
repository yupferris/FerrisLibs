#include <Fbl/BsonObject.h>
#include <Fbl/BsonStringElement.h>
#include <Fbl/BsonObjectElement.h>
#include <Fbl/BsonBinaryElement.h>
#include <Fbl/BsonInt32Element.h>
#include <Fbl/BsonBoolElement.h>

using namespace Fsl;

namespace Fbl
{
	BsonObject::~BsonObject()
	{
		auto values = elements.GetValues();
		for (int i = 0; i < values.Count(); i++)
			delete values[i];
	}

	const Dictionary<String, BsonElement *> BsonObject::GetElements() const
	{
		return elements;
	}

	void BsonObject::AddElement(BsonElement *element)
	{
		elements.Add(element->GetName(), element);
	}

	void BsonObject::AddString(const String& name, const String& value)
	{
		elements.Add(name, new BsonStringElement(name, value));
	}

	void BsonObject::AddObject(const String& name, BsonObject *value)
	{
		elements.Add(name, new BsonObjectElement(name, value));
	}

	void BsonObject::AddBinary(const String& name, const Fsl::List<unsigned char>& value)
	{
		elements.Add(name, new BsonBinaryElement(name, value));
	}

	void BsonObject::AddBinary(const Fsl::String& name, const unsigned char *data, int length)
	{
		elements.Add(name, new BsonBinaryElement(name, data, length));
	}

	void BsonObject::AddInt32(const String& name, int value)
	{
		elements.Add(name, new BsonInt32Element(name, value));
	}

	void BsonObject::AddBool(const Fsl::String& name, bool value)
	{
		elements.Add(name, new BsonBoolElement(name, value));
	}

	const BsonElement *BsonObject::TryGetElement(const Fsl::String& name) const
	{
		return elements.ContainsKey(name) ? elements[name] : nullptr;
	}

	const BsonElement *BsonObject::GetElement(const Fsl::String& name) const
	{
		auto ret = TryGetElement(name);
		if (!ret)
			throw FSL_EXCEPTION("Object did not contain an element with the given name");
		return ret;
	}

	bool BsonObject::TryGetElementValue(const String& name, String& value) const
	{
		auto element = tryGetElement(name, BsonElementType::String);
		if (!element)
			return false;
		value = ((BsonStringElement *)element)->GetValue();
		return true;
	}

	bool BsonObject::TryGetElementValue(const String& name, BsonObject *& value) const
	{
		auto element = tryGetElement(name, BsonElementType::Object);
		if (!element)
			return false;
		value = ((BsonObjectElement *)element)->GetValue();
		return true;
	}

	bool BsonObject::TryGetElementValue(const String& name, Fsl::List<BsonElement *>& value) const
	{
		auto element = tryGetElement(name, BsonElementType::Array);
		if (!element)
			return false;
		value = ((BsonArrayElement *)element)->GetElements();
		return true;
	}

	bool BsonObject::TryGetElementValue(const String& name, List<unsigned char>& value) const
	{
		auto element = tryGetElement(name, BsonElementType::Binary);
		if (!element)
			return false;
		value = ((BsonBinaryElement *)element)->GetValue();
		return true;
	}

	bool BsonObject::TryGetElementValue(const String& name, int& value) const
	{
		auto element = tryGetElement(name, BsonElementType::Int32);
		if (!element)
			return false;
		value = ((BsonInt32Element *)element)->GetValue();
		return true;
	}

	bool BsonObject::TryGetElementValue(const String& name, bool& value) const
	{
		auto element = tryGetElement(name, BsonElementType::Bool);
		if (!element)
			return false;
		value = ((BsonBoolElement *)element)->GetValue();
		return true;
	}

	const String& BsonObject::GetStringValue(const String& name) const
	{
		auto element = getElement(name, BsonElementType::String);
		return ((BsonStringElement *)element)->GetValue();
	}

	BsonObject *BsonObject::GetObjectValue(const String& name) const
	{
		auto element = getElement(name, BsonElementType::Object);
		return ((BsonObjectElement *)element)->GetValue();
	}

	const List<BsonElement *> BsonObject::GetArrayValue(const String& name) const
	{
		auto element = getElement(name, BsonElementType::Array);
		return ((BsonArrayElement *)element)->GetElements();
	}

	const List<unsigned char>& BsonObject::GetBinaryValue(const String& name) const
	{
		auto element = getElement(name, BsonElementType::Binary);
		return ((BsonBinaryElement *)element)->GetValue();
	}

	int BsonObject::GetInt32Value(const String& name) const
	{
		auto element = getElement(name, BsonElementType::Int32);
		return ((BsonInt32Element *)element)->GetValue();
	}

	bool BsonObject::GetBoolValue(const String& name) const
	{
		auto element = getElement(name, BsonElementType::Bool);
		return ((BsonBoolElement *)element)->GetValue();
	}

	const BsonElement *BsonObject::tryGetElement(const Fsl::String& name, BsonElementType type) const
	{
		auto ret = TryGetElement(name);
		if (!ret)
			return nullptr;
		if (ret->GetType() != type)
			return nullptr;
		return ret;
	}

	const BsonElement *BsonObject::getElement(const Fsl::String& name, BsonElementType type) const
	{
		auto ret = GetElement(name);
		if (ret->GetType() != type)
			throw FSL_EXCEPTION("Element type does not match the given type");
		return ret;
	}
}

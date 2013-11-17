#include <Fbl/BsonSerializer.h>
#include <Fbl/BsonStringElement.h>
#include <Fbl/BsonDocumentElement.h>
#include <Fbl/BsonArrayElement.h>
#include <Fbl/BsonBinaryElement.h>
#include <Fbl/BsonInt32Element.h>
#include <Fbl/BsonBoolElement.h>

using namespace Fsl;

namespace Fbl
{
	void BsonSerializer::Serialize(const String& fileName, const BsonDocument *document)
	{
		bson b;
		bson_init(&b);

		serializeDocument(&b, document);

		bson_finish(&b);
		FileStream(fileName, FileStream::FileMode::OpenWrite).Write((const unsigned char *)bson_data(&b), 0, bson_size(&b));

		bson_destroy(&b);
	}

	BsonDocument *BsonSerializer::Deserialize(const String& fileName)
	{
		auto input = File::ReadAllBytes(fileName);
		bson b;
		bson_init_finished_data(&b, (char *)input.GetData(), false);

		bson_iterator it;
		bson_iterator_init(&it, &b);
		auto ret = deserializeDocument(&it);

		bson_destroy(&b);

		return ret;
	}

	void BsonSerializer::serializeDocument(bson *b, const BsonDocument *document)
	{
		auto elements = document->GetElements().GetValues();
		for (int i = 0; i < elements.Count(); i++)
			serializeElement(b, elements[i]);
	}

	void BsonSerializer::serializeElement(bson *b, const BsonElement *element)
	{
		auto elementName = element->GetName().GetData();
		switch (element->GetType())
		{
		case BsonElementType::String:
			bson_append_string(b, elementName, ((BsonStringElement *)element)->GetValue().GetData());
			break;

		case BsonElementType::Document:
			bson_append_start_object(b, elementName);
			serializeDocument(b, ((BsonDocumentElement *)element)->GetValue());
			bson_append_finish_object(b);
			break;

		case BsonElementType::Array:
			{
				auto arrayElement = (BsonArrayElement *)element;
				bson_append_start_array(b, elementName);
				for (int i = 0; i < arrayElement->GetElements().Count(); i++)
					serializeElement(b, arrayElement->GetElements()[i]);
				bson_append_finish_array(b);
			}
			break;

		case BsonElementType::Binary:
			{
				auto binElement = (BsonBinaryElement *)element;
				bson_append_binary(b, elementName, 8, (const char *)binElement->GetValue().GetData(), binElement->GetValue().Count());
			}
			break;

		case BsonElementType::Int32:
			bson_append_int(b, elementName, ((BsonInt32Element *)element)->GetValue());
			break;

		case BsonElementType::Bool:
			bson_append_bool(b, elementName, ((BsonBoolElement *)element)->GetValue() ? 1 : 0);
			break;

		default:
			throw FSL_EXCEPTION("Unsupported element type");
		}
	}

	BsonDocument *BsonSerializer::deserializeDocument(bson_iterator *it)
	{
		auto ret = new BsonDocument();

		while (true)
		{
			auto element = deserializeElement(it);
			if (!element)
				break;
			ret->AddElement(element);
		}

		return ret;
	}

	BsonElement *BsonSerializer::deserializeElement(bson_iterator *it)
	{
		if (!bson_iterator_more(it) || !bson_iterator_next(it))
			return nullptr;

		auto type = bson_iterator_type(it);
		auto name = bson_iterator_key(it);

		switch (type)
		{
		case BSON_STRING:
			return new BsonStringElement(name, bson_iterator_string(it));

		case BSON_OBJECT:
			{
				bson_iterator it2;
				bson_iterator_subiterator(it, &it2);
				return new BsonDocumentElement(name, deserializeDocument(&it2));
			}

		case BSON_ARRAY:
			{
				bson_iterator it2;
				bson_iterator_subiterator(it, &it2);

				auto ret = new BsonArrayElement(name);
				while (true)
				{
					auto element = deserializeElement(&it2);
					if (!element)
						break;
					ret->AddElement(element);
				}

				return ret;
			}
			break;

		case BSON_BINDATA:
			{
				int len = bson_iterator_bin_len(it);
				List<unsigned char> value(len);
				auto buf = (const unsigned char *)bson_iterator_bin_data(it);
				for (int i = 0; i < len; i++)
					value.Add(buf[i]);

				return new BsonBinaryElement(name, value);
			}

		case BSON_INT:
			return new BsonInt32Element(name, bson_iterator_int(it));

		case BSON_BOOL:
			return new BsonBoolElement(name, bson_iterator_bool(it) != 0);
		}

		throw FSL_EXCEPTION("Unsupported element type");
	}
}

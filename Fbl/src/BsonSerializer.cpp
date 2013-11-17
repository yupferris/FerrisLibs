#include <Fbl/BsonSerializer.h>
#include <Fbl/BsonStringElement.h>
#include <Fbl/BsonDocumentElement.h>
#include <Fbl/BsonBinaryElement.h>
#include <Fbl/BsonInt32Element.h>

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
		auto elements = document->GetElements();
		for (int i = 0; i < elements.Count(); i++)
		{
			auto element = elements[i];
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

			case BsonElementType::Binary:
				{
					auto binElement = (BsonBinaryElement *)element;
					bson_append_binary(b, elementName, 8, (const char *)binElement->GetValue().GetData(), binElement->GetValue().Count());
				}
				break;

			case BsonElementType::Int32:
				bson_append_int(b, elementName, ((BsonInt32Element *)element)->GetValue());
				break;

			default:
				throw FSL_EXCEPTION("Unsupported element type");
			}
		}
	}

	BsonDocument *BsonSerializer::deserializeDocument(bson_iterator *it)
	{
		auto ret = new BsonDocument();

		while (bson_iterator_more(it) && bson_iterator_next(it))
		{
			auto type = bson_iterator_type(it);
			auto name = bson_iterator_key(it);

			switch (type)
			{
			case BSON_STRING:
				ret->AddString(name, bson_iterator_string(it));
				break;

			case BSON_OBJECT:
				{
					bson_iterator it2;
					bson_iterator_subiterator(it, &it2);

					ret->AddDocument(name, deserializeDocument(&it2));
				}
				break;

			case BSON_BINDATA:
				{
					int len = bson_iterator_bin_len(it);
					List<unsigned char> value(len);
					auto buf = (const unsigned char *)bson_iterator_bin_data(it);
					for (int i = 0; i < len; i++)
						value.Add(buf[i]);

					ret->AddBinary(name, value);
				}
				break;

			case BSON_INT:
				ret->AddInt32(name, bson_iterator_int(it));
				break;

			default:
				throw FSL_EXCEPTION("Unsupported element type");
			}
		}

		return ret;
	}
}

#ifndef __FBL_BSONSERIALIZER_H__
#define __FBL_BSONSERIALIZER_H__

#include "BsonDocument.h"

#ifndef MONGO_STATIC_BUILD
#define MONGO_STATIC_BUILD
#endif
#ifndef MONGO_HAVE_STDINT
#define MONGO_HAVE_STDINT
#endif
#include "../../src/mongo-c-driver/src/bson.h"

namespace Fbl
{
	class BsonSerializer
	{
	public:
		static void Serialize(const Fsl::String& fileName, const BsonDocument *document);
		static BsonDocument *Deserialize(const Fsl::String& fileName);

	private:
		static void serializeDocument(bson *b, const BsonDocument *document);
		static void serializeElement(bson *b, const BsonElement *element);
		static BsonDocument *deserializeDocument(bson_iterator *it);
		static BsonElement *deserializeElement(bson_iterator *it);
	};
}

#endif

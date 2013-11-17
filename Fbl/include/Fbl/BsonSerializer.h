#ifndef __FBL_BSONSERIALIZER_H__
#define __FBL_BSONSERIALIZER_H__

#include "BsonDocument.h"

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
		static BsonDocument *deserializeDocument(bson_iterator *it);
	};
}

#endif

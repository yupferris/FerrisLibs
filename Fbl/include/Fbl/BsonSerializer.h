#ifndef __FBL_BSONSERIALIZER_H__
#define __FBL_BSONSERIALIZER_H__

#include "BsonObject.h"

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
		static void Serialize(const Fsl::String& fileName, const BsonObject *object);
		static BsonObject *Deserialize(const Fsl::String& fileName);

	private:
		static void serializeObject(bson *b, const BsonObject *object);
		static void serializeElement(bson *b, const BsonElement *element);
		static BsonObject *deserializeObject(bson_iterator *it);
		static BsonElement *deserializeElement(bson_iterator *it);
	};
}

#endif

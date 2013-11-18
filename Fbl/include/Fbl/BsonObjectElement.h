#ifndef __FBL_BSONOBJECTELEMENT_H__
#define __FBL_BSONOBJECTELEMENT_H__

#include "BsonElement.h"

namespace Fbl
{
	class BsonObject;

	class BsonObjectElement : public BsonElement
	{
	public:
		BsonObjectElement(const Fsl::String& name, BsonObject *value);
		virtual ~BsonObjectElement();

		virtual BsonElementType GetType() const;

		BsonObject *GetValue() const;

	private:
		BsonObject *value;
	};
}

#endif

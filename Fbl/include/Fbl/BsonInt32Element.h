#ifndef __FBL_BSONINT32ELEMENT_H__
#define __FBL_BSONINT32ELEMENT_H__

#include "BsonElement.h"

namespace Fbl
{
	class BsonInt32Element : public BsonElement
	{
	public:
		BsonInt32Element(const Fsl::String& name, int value);
		virtual ~BsonInt32Element();

		virtual BsonElementType GetType() const;

		int GetValue() const;

	private:
		int value;
	};
}

#endif

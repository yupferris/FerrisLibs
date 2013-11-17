#ifndef __FBL_BSONBOOLELEMENT_H__
#define __FBL_BSONBOOLELEMENT_H__

#include "BsonElement.h"

namespace Fbl
{
	class BsonBoolElement : public BsonElement
	{
	public:
		BsonBoolElement(const Fsl::String& name, bool value);
		virtual ~BsonBoolElement();

		virtual BsonElementType GetType() const;

		bool GetValue() const;

	private:
		bool value;
	};
}

#endif

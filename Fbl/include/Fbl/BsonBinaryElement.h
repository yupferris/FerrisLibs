#ifndef __FBL_BSONBINARYELEMENT_H__
#define __FBL_BSONBINARYELEMENT_H__

#include "BsonElement.h"

namespace Fbl
{
	class BsonBinaryElement : public BsonElement
	{
	public:
		BsonBinaryElement(const Fsl::String& name, const Fsl::List<unsigned char>& value);
		virtual ~BsonBinaryElement();

		virtual BsonElementType GetType() const;

		const Fsl::List<unsigned char>& GetValue() const;

	private:
		Fsl::List<unsigned char> value;
	};
}

#endif

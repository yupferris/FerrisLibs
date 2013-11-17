#ifndef __FBL_BSONDOCUMENTELEMENT_H__
#define __FBL_BSONDOCUMENTELEMENT_H__

#include "BsonElement.h"

namespace Fbl
{
	class BsonDocument;

	class BsonDocumentElement : public BsonElement
	{
	public:
		BsonDocumentElement(const Fsl::String& name, BsonDocument *value);
		virtual ~BsonDocumentElement();

		virtual BsonElementType GetType() const;

		BsonDocument *GetValue() const;

	private:
		BsonDocument *value;
	};
}

#endif
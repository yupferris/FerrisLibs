#ifndef __FBL_BSONSTRINGELEMENT_H__
#define __FBL_BSONSTRINGELEMENT_H__

#include "BsonElement.h"

namespace Fbl
{
	class BsonStringElement : public BsonElement
	{
	public:
		BsonStringElement(const Fsl::String& name, const Fsl::String& value);
		virtual ~BsonStringElement();

		virtual BsonElementType GetType() const;

		const Fsl::String& GetValue() const;

	private:
		Fsl::String value;
	};
}

#endif

#ifndef __FBL_BSONARRAYELEMENT_H__
#define __FBL_BSONARRAYELEMENT_H__

#include "BsonElement.h"

namespace Fbl
{
	class BsonObject;

	class BsonArrayElement : public BsonElement
	{
	public:
		BsonArrayElement(const Fsl::String& name);
		virtual ~BsonArrayElement();

		virtual BsonElementType GetType() const;

		void AddElement(BsonElement *element);

		void AddString(const Fsl::String& value);
		void AddObject(BsonObject *value);
		void AddBinary(const Fsl::List<unsigned char>& value);
		void AddBinary(const unsigned char *data, int length);
		void AddInt32(int value);
		void AddBool(bool value);

		Fsl::List<BsonElement *> GetElements() const;

	private:
		Fsl::List<BsonElement *> elements;
	};
}

#endif

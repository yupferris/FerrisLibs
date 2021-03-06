#ifndef __FBL_BSONOBJECT_H__
#define __FBL_BSONOBJECT_H__

#include "BsonElement.h"
#include "BsonStringElement.h"
#include "BsonObjectElement.h"
#include "BsonArrayElement.h"
#include "BsonBinaryElement.h"
#include "BsonInt32Element.h"
#include "BsonBoolElement.h"

namespace Fbl
{
	class BsonObject
	{
	public:
		~BsonObject();

		const Fsl::Dictionary<Fsl::String, BsonElement *> GetElements() const;

		void AddElement(BsonElement *element);

		void AddString(const Fsl::String& name, const Fsl::String& value);
		void AddObject(const Fsl::String& name, BsonObject *value);
		void AddBinary(const Fsl::String& name, const Fsl::List<unsigned char>& value);
		void AddBinary(const Fsl::String& name, const unsigned char *data, int length);
		void AddInt32(const Fsl::String& name, int value);
		void AddBool(const Fsl::String& name, bool value);

		const BsonElement *TryGetElement(const Fsl::String& name) const;
		const BsonElement *GetElement(const Fsl::String& name) const;

		bool TryGetElementValue(const Fsl::String& name, Fsl::String& value) const;
		bool TryGetElementValue(const Fsl::String& name, BsonObject *& value) const;
		bool TryGetElementValue(const Fsl::String& name, Fsl::List<BsonElement *>& value) const;
		bool TryGetElementValue(const Fsl::String& name, Fsl::List<unsigned char>& value) const;
		bool TryGetElementValue(const Fsl::String& name, int& value) const;
		bool TryGetElementValue(const Fsl::String& name, bool& value) const;

		const Fsl::String& GetStringValue(const Fsl::String& name) const;
		BsonObject *GetObjectValue(const Fsl::String& name) const;
		const Fsl::List<BsonElement *> GetArrayValue(const Fsl::String& name) const;
		const Fsl::List<unsigned char>& GetBinaryValue(const Fsl::String& name) const;
		int GetInt32Value(const Fsl::String& name) const;
		bool GetBoolValue(const Fsl::String& name) const;

	private:
		const BsonElement *tryGetElement(const Fsl::String& name, BsonElementType type) const;
		const BsonElement *getElement(const Fsl::String& name, BsonElementType type) const;

		Fsl::Dictionary<Fsl::String, BsonElement *> elements;
	};
}

#endif

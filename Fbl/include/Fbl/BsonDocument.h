#ifndef __FBL_BSONDOCUMENT_H__
#define __FBL_BSONDOCUMENT_H__

#include "BsonElement.h"

namespace Fbl
{
	class BsonDocument
	{
	public:
		~BsonDocument();

		const Fsl::List<BsonElement *> GetElements() const;

		void AddString(const Fsl::String& name, const Fsl::String& value);
		void AddDocument(const Fsl::String& name, BsonDocument *document);
		void AddBinary(const Fsl::String& name, const Fsl::List<unsigned char>& value);
		void AddInt32(const Fsl::String& name, int value);

	private:
		Fsl::List<BsonElement *> elements;
	};
}

#endif

#ifndef __FBL_BSONELEMENT_H__
#define __FBL_BSONELEMENT_H__

#include <Fsl.h>

namespace Fbl
{
	enum class BsonElementType
	{
		String,
		Document,
		Array,
		Binary,
		Int32,
		Bool,
	};

	class BsonElement
	{
	public:
		BsonElement(const Fsl::String& name);
		virtual ~BsonElement();

		virtual BsonElementType GetType() const = 0;

		const Fsl::String& GetName() const;

	private:
		Fsl::String name;
	};
}

#endif

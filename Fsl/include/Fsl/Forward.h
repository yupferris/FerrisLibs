#ifndef __FSL_FORWARD_H__
#define __FSL_FORWARD_H__

namespace Fsl
{
	template <typename TTo, typename TFrom> TTo&& Forward(TFrom& from)
	{
		return static_cast<TTo&&>(from);
	}
}

#endif

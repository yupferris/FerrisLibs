#ifndef __FSL_MUTEX_H__
#define __FSL_MUTEX_H__

namespace Fsl
{
	class Mutex
	{
	public:
		Mutex *Create();

		virtual ~Mutex();

		virtual void Lock() = 0;
		virtual void Unlock() = 0;

	protected:
		Mutex();
	};
}

#endif

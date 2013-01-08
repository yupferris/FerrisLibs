#ifndef __FSL_FUNCTION_H__
#define __FSL_FUNCTION_H__

#include "Forward.h"

namespace Fsl
{
	// TODO: Finish once MSVC supports variadic templates.

	/*template <typename T> class Function;

	template <typename TResult, typename... TArgs> class Function<TResult(TArgs...)>
	{
	public:
		Function()
		{
			functor = nullptr;
		}

		Function(TResult (*function)(TArgs...))
		{
			functor = new GlobalFunctor(function);
		}

		Function(const Function& function)
		{
			functor = function.functor;
			if (functor) function.functor->RefCount++;
		}

		Function& operator=(const Function& function)
		{
			functor = function.functor;
			if (functor) function.functor->RefCount++;
			return *this;
		}

		~Function()
		{
			if (functor)
			{
				functor->RefCount--;
				if (!functor->RefCount) delete functor;
			}
		}

		operator bool() const
		{
			return functor;
		}

		TResult operator()(TArgs... args) const
		{
			return (*functor)(Forward<TArgs>(args)...);
		}

	private:
		class Functor
		{
		public:
			int RefCount;

			Functor()
			{
				RefCount = 0;
			}

			virtual ~Functor() { }

			virtual TResult operator()(TArgs... args) const = 0;
		};

		class GlobalFunctor
		{
		public:
			GlobalFunctor(TResult (*function)(TArgs...))
			{
				this->function = function;
			}

			virtual TResult operator()(TArgs... args)
			{
				return function(Forward<TArgs>(args)...);
			}

		private:
			TResult (*function)(TArgs...);
		};

		Functor *functor;
	};*/
}

#endif

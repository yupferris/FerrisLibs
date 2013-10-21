#ifndef __FSL_EVENT_H__
#define __FSL_EVENT_H__

#include "List.h"

#include <functional>

// TODO: Consolidate into one Event class using Fsl::Function once MSVC supports variadic templates.

namespace Fsl
{
	class Event
	{
	public:
		typedef std::function<void()> Handler;

		Event& operator +=(Handler handler)
		{
			handlers.Add(handler);
			return *this;
		}

		Event& operator -=(Handler handler)
		{
			for (int i = 0; i < handlers.Count(); i++)
			{
				if (*handlers[i].target<void()>() == *handler.target<void()>())
				{
					handlers.RemoveAt(i);
					break;
				}
			}
			return *this;
		}

		void operator()()
		{
			for (int i = 0; i < handlers.Count(); i++) handlers[i]();
		}

	private:
		Fsl::List<Handler> handlers;
	};

	template <typename T> class Event1
	{
	public:
		typedef std::function<void(T)> Handler;

		Event1& operator +=(Handler handler)
		{
			for (int i = 0; i < handlers.Count(); i++)
			{
				if (*handlers[i].target<void(T)>() == *handler.target<void(T)>())
				{
					handlers.RemoveAt(i);
					break;
				}
			}
			return *this;
		}

		void operator()(T arg)
		{
			for (int i = 0; i < handlers.Count(); i++) handlers[i](arg);
		}

	private:
		Fsl::List<Handler> handlers;
	};

	template <typename T1, typename T2> class Event2
	{
	public:
		typedef std::function<void(T1, T2)> Handler;

		Event2& operator +=(Handler handler)
		{
			for (int i = 0; i < handlers.Count(); i++)
			{
				if (*handlers[i].target<void(T1, T2)>() == *handler.target<void(T1, T2)>())
				{
					handlers.RemoveAt(i);
					break;
				}
			}
			return *this;
		}

		void operator()(T1 arg1, T2 arg2)
		{
			for (int i = 0; i < handlers.Count(); i++) handlers[i](arg1, arg2);
		}

	private:
		Fsl::List<Handler> handlers;
	};
};

#endif

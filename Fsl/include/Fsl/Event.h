#ifndef __FSL_EVENT_H__
#define __FSL_EVENT_H__

#include "Dictionary.h"
#include "Exception.h"

#include <functional>

// TODO: Consolidate into one Event class using Fsl::Function once MSVC supports variadic templates.

namespace Fsl
{
	class Event
	{
	public:
		typedef std::function<void()> Handler;

		int operator +=(Handler handler)
		{
			int key = 0;
			while (handlers.ContainsKey(key))
			{
				key++;
				if (!key) throw FSL_EXCEPTION("Too many event handlers");
			}
			handlers.Add(key, handler);
			return key;
		}

		Event& operator -=(int key)
		{
			handlers.Remove(key);
			return *this;
		}

		void operator()()
		{
			auto values = handlers.GetValues();
			for (int i = 0; i < values.Count(); i++) values[i]();
		}

	private:
		Fsl::Dictionary<int, Handler> handlers;
	};

	template <typename T> class Event1
	{
	public:
		typedef std::function<void(T)> Handler;

		int operator +=(Handler handler)
		{
			int key = 0;
			while (handlers.ContainsKey(key))
			{
				key++;
				if (!key) throw FSL_EXCEPTION("Too many event handlers");
			}
			handlers.Add(key, handler);
			return key;
		}

		Event1& operator -=(int key)
		{
			handlers.Remove(key);
			return *this;
		}

		void operator()(T arg)
		{
			auto values = handlers.GetValues();
			for (int i = 0; i < values.Count(); i++) values[i](arg);
		}

	private:
		Fsl::Dictionary<int, Handler> handlers;
	};

	template <typename T1, typename T2> class Event2
	{
	public:
		typedef std::function<void(T1, T2)> Handler;

		int operator +=(Handler handler)
		{
			int key = 0;
			while (handlers.ContainsKey(key))
			{
				key++;
				if (!key) throw FSL_EXCEPTION("Too many event handlers");
			}
			handlers.Add(key, handler);
			return key;
		}

		Event2& operator -=(int key)
		{
			handlers.Remove(key);
			return *this;
		}

		void operator()(T1 arg1, T2 arg2)
		{
			auto values = handlers.GetValues();
			for (int i = 0; i < values.Count(); i++) values[i](arg1, arg2);
		}

	private:
		Fsl::Dictionary<int, Handler> handlers;
	};
};

#endif

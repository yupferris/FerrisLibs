#ifndef __FSL_DICTIONARY_H__
#define __FSL_DICTIONARY_H__

#include "List.h"

namespace Fsl
{
	template <typename TKey, typename TValue> class Dictionary
	{
	public:
		Dictionary()
		{
		}

		Dictionary(const Dictionary& d)
		{
			keys = d.keys;
			values = d.values;
		}

		Dictionary& operator =(const Dictionary& d)
		{
			if (this != &d)
			{
				keys = d.keys;
				values = d.values;
			}
			return *this;
		}

		void Clear()
		{
			keys.Clear();
			values.Clear();
		}
		
		void Add(const TKey& key, const TValue& value)
		{
			if (keys.Contains(key)) throw FSL_EXCEPTION("Dictionary already contains the given key");
			keys.Add(key);
			values.Add(value);
		}

		void Remove(const TKey& key)
		{
			for (int i = 0; i < keys.Count; i++)
			{
				if (key == keys[i])
				{
					keys.RemoveAt(i);
					values.RemoveAt(i);
					return;
				}
			}
			throw FSL_EXCEPTION("Dictionary does not contain the given key");
		}

		int Count() const
		{
			return keys.Count();
		}

		bool ContainsKey(const TKey& key) const
		{
			return keys.Contains(key);
		}

		TValue& operator [](const TKey& key) const
		{
			for (int i = 0; i < keys.Count(); i++)
			{
				if (key == keys[i]) return values[i];
			}
			throw FSL_EXCEPTION("Dictionary does not contain the given key");
		}

		const List<TKey>& GetKeys() const
		{
			return keys;
		}

		const List<TValue>& GetValues() const
		{
			return values;
		}

	private:
		List<TKey> keys;
		List<TValue> values;
	};
}

#endif

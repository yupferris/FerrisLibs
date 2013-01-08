#ifndef __FSL_LIST_H__
#define __FSL_LIST_H__

#include "Exception.h"

namespace Fsl
{
	template <typename T> class List
	{
	public:
		List(int initialSize = 0)
		{
			size = initialSize;
			count = 0;
			data = size ? new T[size] : nullptr;
		}

		List(const List& l)
		{
			size = l.size;
			count = l.count;
			if (l.data)
			{
				data = new T[size];
				for (int i = 0; i < count; i++) data[i] = l.data[i];
			}
			else
			{
				data = nullptr;
			}
		}

		~List()
		{
			Clear();
		}

		List& operator =(const List& l)
		{
			if (this != &l)
			{
				Clear();
				size = l.size;
				count = l.count;
				if (l.data)
				{
					data = new T[size];
					for (int i = 0; i < count; i++) data[i] = l.data[i];
				}
				else
				{
					data = nullptr;
				}
			}
			return *this;
		}

		bool Contains(const T& item) const
		{
			for (int i = 0; i < count; i++)
			{
				if (data[i] == item) return true;
			}
			return false;
		}

		void Add(const T& item)
		{
			count++;
			ensureCapacity();
			data[count - 1] = item;
		}

		List<T>& operator +=(const T& item)
		{
			Add(item);
			return *this;
		}

		void Remove(const T& item)
		{
			for (int i = 0; i < count; i++)
			{
				if (data[i] == item)
				{
					RemoveAt(i);
					return;
				}
			}
			throw FSL_EXCEPTION("List does not contain the given item");
		}

		List<T>& operator -=(const T& item)
		{
			Remove(item);
			return *this;
		}

		void Insert(int index, const T& item)
		{
			count++;
			ensureCapacity();
			if (count - 1)
			{
				for (int i = count - 1; i >= index; i--) data[i + 1] = data[i];
			}
			data[index] = item;
		}

		void RemoveAt(int index)
		{
			if (index < 0 || index >= count) throw FSL_EXCEPTION("Index out of bounds");
			count--;
			for (int i = index; i <= count; i++) data[i] = data[i + 1];
		}

		void AddRange(const List<T>& l)
		{
			int oldCount = count;
			count += l.Count();
			ensureCapacity();
			for (int i = 0; i < l.Count(); i++) data[oldCount + i] = l[i];
		}

		void RemoveRange(int start, int end)
		{
			for (int i = 0; i < end - start; i++) RemoveAt(start);
		}

		int Count() const
		{
			return count;
		}

		void Clear()
		{
			size = count = 0;
			if (data)
			{
				delete [] data;
				data = nullptr;
			}
		}

		T& At(int index) const
		{
			if (index < 0 || index >= count) throw FSL_EXCEPTION("Index out of bounds");
			return data[index];
		}

		T& operator [](int index) const
		{
			return At(index);
		}

		const T *GetData() const
		{
			return data;
		}

		static List<T> Merge(const List<T>& l1, const List<T>& l2)
		{
			List<T> merged;
			merged.count = l1.Count() + l2.Count();
			merged.ensureCapacity();
			for (int i = 0; i < l1.Count(); i++) merged[i] = l1[i];
			for (int i = 0; i < l2.Count(); i++) merged[i + l1.Count()] = l2[i];
			return merged;
		}

	private:
		void ensureCapacity()
		{
			if (count > size)
			{
				int newSize = size;
				while (newSize < count) newSize += 8;
				auto newData = new T[newSize];
				for (int i = 0; i < size; i++) newData[i] = data[i];
				size = newSize;
				if (data) delete [] data;
				data = newData;
			}
		}

		int size, count;
		T *data;
	};
}

#endif

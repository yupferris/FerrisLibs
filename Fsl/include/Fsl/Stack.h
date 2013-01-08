#ifndef __FSL_STACK_H__
#define __FSL_STACK_H__

#include "Exception.h"

namespace Fsl
{
	template <typename T> class Stack
	{
	public:
		Stack(int size = 100)
		{
			this->size = size;
			pos = 0;
			data = new T[size];
		}

		~Stack()
		{
			delete [] data;
		}

		void Push(const T& item)
		{
			if (pos >= size) throw FSL_EXCEPTION("Stack overflow occurred");
			data[pos] = item;
			pos++;
		}

		T Pop()
		{
			if (pos < 1) throw FSL_EXCEPTION("Stack underflow occurred");
			pos--;
			return data[pos];
		}

	private:
		int size;
		int pos;
		T *data;
	};
}

#endif

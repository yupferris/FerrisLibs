#ifndef __FSL_STRING_H__
#define __FSL_STRING_H__

#include "StringDecl.h"
#include "Exception.h"
#include "List.h"

namespace Fsl
{
	template <typename T> Stringt<T>::Stringt()
	{
		stringData = nullptr;
	}

	template <typename T> Stringt<T>::Stringt(const Stringt& s)
	{
		stringData = s.stringData;
		if (stringData) stringData->RefCount++;
	}

	template <typename T> Stringt<T>::Stringt(const T *s)
	{
		stringData = new StringData(s);
	}

	template <typename T> Stringt<T>::Stringt(T c)
	{
		T tmpData[2];
		tmpData[0] = c;
		tmpData[1] = 0;
		stringData = new StringData(tmpData);
	}

	template <typename T> Stringt<T>::Stringt(long long l)
	{
		init(l);
	}

	template <typename T> Stringt<T>::Stringt(int i)
	{
		init(i);
	}

	template <typename T> Stringt<T>::Stringt(float f, int decimalPlaces)
	{
		init((double)f, decimalPlaces);
	}

	template <typename T> Stringt<T>::Stringt(double d, int decimalPlaces)
	{
		init(d, decimalPlaces);
	}

	template <typename T> Stringt<T>::~Stringt()
	{
		Clear();
	}

	template <typename T> Stringt<T>& Stringt<T>::operator =(const Stringt<T>& s)
	{
		if (this != &s)
		{
			Clear();
			stringData = s.stringData;
			if (stringData) stringData->RefCount++;
		}
		return *this;
	}

	template <typename T> Stringt<T>& Stringt<T>::operator =(const T *s)
	{
		Clear();
		stringData = new StringData(s);
		return *this;
	}

	template <typename T> void Stringt<T>::Clear()
	{
		if (stringData)
		{
			stringData->RefCount--;
			if (!stringData->RefCount)
			{
				delete stringData;
				stringData = nullptr;
			}
		}
	}

	template <typename T> int Stringt<T>::Length() const
	{
		return stringData ? stringData->Size - 1 : 0;
	}

	template <typename T> T& Stringt<T>::Get(int index)
	{
		if (!stringData) throw FSL_EXCEPTION("Cannot index empty string");
		if (index < 0 || index >= stringData->Size) throw FSL_EXCEPTION("Index out of bounds");
		ensureUniqueStringData();
		return stringData->Data[index];
	}

	template <typename T> T& Stringt<T>::operator [](int index)
	{
		return Get(index);
	}

	template <typename T> const T& Stringt<T>::Get(int index) const
	{
		if (!stringData) throw FSL_EXCEPTION("Cannot index empty string");
		if (index < 0 || index >= stringData->Size) throw FSL_EXCEPTION("Index out of bounds");
		return stringData->Data[index];
	}

	template <typename T> const T& Stringt<T>::operator [](int index) const
	{
		return Get(index);
	}

	template <typename T> const T *Stringt<T>::GetData() const
	{
		return stringData ? stringData->Data : nullptr;
	}

	template <typename T> bool Stringt<T>::operator ==(const Stringt& s) const
	{
		if (stringData == s.stringData) return true;
		if (!stringData || !s.stringData || stringData->Size != s.stringData->Size) return false;
		for (int i = 0; i < stringData->Size; i++)
		{
			if (stringData->Data[i] != s.stringData->Data[i]) return false;
		}
		return true;
	}

	template <typename T> bool Stringt<T>::operator ==(const T *s) const
	{
		return *this == Stringt<T>(s);
	}

	template <typename T> bool Stringt<T>::operator !=(const Stringt& s) const
	{
		return !(*this == s);
	}

	template <typename T> bool Stringt<T>::operator !=(const T *s) const
	{
		return !(*this == s);
	}

	template <typename T> Stringt<T> Stringt<T>::operator +(const Stringt& s) const
	{
		if (!s.Length()) return Stringt<T>(*this);
		int newSize = Length() + s.Length();
		T *newData = new T[newSize + 1];
		for (int i = 0; i < Length(); i++) newData[i] = Get(i);
		for (int i = 0; i < s.Length(); i++) newData[i + Length()] = s[i];
		newData[newSize] = 0;
		return Stringt<T>(newData);
	}

	template <typename T> Stringt<T> Stringt<T>::operator +(const T *s) const
	{
		return *this + Stringt<T>(s);
	}

	template <typename T> Stringt<T> Stringt<T>::operator +(T c) const
	{
		return *this + Stringt<T>(c);
	}

	template <typename T> Stringt<T> Stringt<T>::operator +(long long l) const
	{
		return *this + Stringt<T>(l);
	}

	template <typename T> Stringt<T> Stringt<T>::operator +(int i) const
	{
		return *this + Stringt<T>(i);
	}

	template <typename T> Stringt<T> Stringt<T>::operator +(float f) const
	{
		return *this + Stringt<T>(f);
	}

	template <typename T> Stringt<T> Stringt<T>::operator +(double d) const
	{
		return *this + Stringt<T>(d);
	}

	template <typename T> Stringt<T>& Stringt<T>::operator +=(const Stringt& s)
	{
		return *this = *this + s;
	}

	template <typename T> Stringt<T>& Stringt<T>::operator +=(const T *s)
	{
		return *this = *this + s;
	}

	template <typename T> Stringt<T>& Stringt<T>::operator +=(T c)
	{

		return *this = *this + c;
	}

	template <typename T> Stringt<T>& Stringt<T>::operator +=(long long l)
	{

		return *this = *this + l;
	}

	template <typename T> Stringt<T>& Stringt<T>::operator +=(int i)
	{

		return *this = *this + i;
	}

	template <typename T> Stringt<T>& Stringt<T>::operator +=(float f)
	{

		return *this = *this + f;
	}

	template <typename T> Stringt<T>& Stringt<T>::operator +=(double d)
	{

		return *this = *this + d;
	}

	template <typename T> bool Stringt<T>::StartsWith(T c) const
	{
		if (!Length() || stringData->Data[0] != c) return false;
		return true;
	}

	template <typename T> bool Stringt<T>::StartsWith(const Stringt& s) const
	{
		auto length = Length();
		auto sLength = s.Length();
		if (!Length() || length < sLength) return false;
		for (int i = 0; i < sLength; i++)
		{
			if (stringData->Data[i] != s[i]) return false;
		}
		return true;
	}

	template <typename T> bool Stringt<T>::EndsWith(T c) const
	{
		auto length = Length();
		if (!length || stringData->Data[length - 1] != c) return false;
		return true;
	}

	template <typename T> bool Stringt<T>::EndsWith(const Stringt& s) const
	{
		auto length = Length();
		auto sLength = s.Length();
		if (!Length() || length < sLength) return false;
		for (int i = 0; i < sLength; i++)
		{
			if (stringData->Data[i + (length - sLength)] != s[i]) return false;
		}
		return true;
	}

	template <typename T> Stringt<T> Stringt<T>::Substring(int startPos) const
	{
		return Substring(startPos, Length() - startPos);
	}

	template <typename T> Stringt<T> Stringt<T>::Substring(int startPos, int len) const
	{
		if (!stringData) throw FSL_EXCEPTION("Cannot take substring from empty string");
		if (startPos < 0 || startPos >= Length()) throw FSL_EXCEPTION("Invalid starting position specified");
		auto length = Length();
		if (len < 0 || len > length) throw FSL_EXCEPTION("Invalid length specified");
		if (startPos + len > length) throw FSL_EXCEPTION("Invalid starting position and length specified");
		Stringt<T> ret;
		if (len - startPos) ret.stringData = new StringData(stringData->Data + startPos, len);
		return ret;
	}

	template <typename T> Stringt<T> Stringt<T>::Replace(T oldValue, T newValue) const
	{
		Stringt<T> ret(*this);
		bool hasFoundMatch = false;
		for (int i = 0; i < Length(); i++)
		{
			if (ret.stringData->Data[i] == oldValue)
			{
				if (!hasFoundMatch)
				{
					ret.ensureUniqueStringData();
					hasFoundMatch = true;
				}
				ret.stringData->Data[i] = newValue;
			}
		}
		return ret;
	}

	template <typename T> int Stringt<T>::LastIndexOf(T c) const
	{
		if (!stringData) throw FSL_EXCEPTION("Cannot search empty string");
		int i = Length() - 1;
		for (; i >= 0; i--)
		{
			if (stringData->Data[i] == c) break;
		}
		return i;
	}

	template <typename T> List<Stringt<T>> Stringt<T>::Split(T c) const
	{
		List<Stringt<T>> ret;
		if (stringData)
		{
			int startPos = 0;
			int pos;
			for (pos = startPos; pos < Length(); pos++)
			{
				if (stringData->Data[pos] == c)
				{
					ret.Add(Substring(startPos, pos - startPos));
					startPos = pos + 1;
				}
			}
			if (startPos < Length()) ret.Add(Substring(startPos, pos - startPos));
		}
		return ret;
	}

	template <typename T> Stringt<T> Stringt<T>::ToLower() const
	{
		auto ret = *this;
		for (int i = 0; i < ret.Length(); i++)
		{
			T c = ret[i];
			if (c >= 'A' && c <= 'Z') ret[i] = c - 'A' + 'a';
		}
		return ret;
	}

	template <typename T> Stringt<T> Stringt<T>::Trim() const
	{
		if (!stringData) return *this;
		int startPos = 0;
		int endPos = Length() - 1;
		while (startPos < Length() && isWhitespace(stringData->Data[startPos])) startPos++;
		while (endPos > 0 && isWhitespace(stringData->Data[endPos])) endPos--;
		return Substring(startPos, endPos + 1 - startPos);
	}

	template <typename T> bool Stringt<T>::TryParseInt(int& value) const
	{
		if (!stringData) return false;
		value = 0;
		for (int i = 0; i < Length(); i++)
		{
			auto c = stringData->Data[i];
			if (!isDigit(c)) return false;
			value = value * 10 + (c - '0');
		}
		return true;
	}

	template <typename T> bool Stringt<T>::isWhitespace(T c)
	{
		return
			c == ' ' ||
			c == '\t' ||
			c == '\r' ||
			c == '\n';
	}

	template <typename T> bool Stringt<T>::isDigit(T c)
	{
		return c >= '0' && c <= '9';
	}

	template <typename T> void Stringt<T>::init(long long l)
	{
		long long i = l;
		int length = 0;
		while (i)
		{
			i /= 10;
			length++;
		}
		if (!length) length = 1;
		T *tmpBuf = new T[length + 1];
		tmpBuf[length] = 0;
		for (i = length - 1; i >= 0; i--)
		{
			tmpBuf[i] = '0' + (l % 10);
			l /= 10;
		}
		stringData = new StringData(tmpBuf);
		delete [] tmpBuf;
	}

	template <typename T> void Stringt<T>::init(double d, int decimalPlaces)
	{
		stringData = nullptr;
		int i = (int)d;
		double fract = d - (double)i;
		for (int j = 0; j < decimalPlaces; j++) fract *= 10.0;
		*this = Stringt<T>(i) + "." + Stringt<T>((int)fract);
	}

	template <typename T> void Stringt<T>::ensureUniqueStringData()
	{
		if (stringData->RefCount != 1)
		{
			stringData->RefCount--;
			stringData = new StringData(stringData->Data);
		}
	}

	template <typename T> Stringt<T>::StringData::StringData(const T *data)
	{
		Size = 0;
		while (data[Size] != 0) Size++;
		Size++;
		Data = new T[Size];
		for (int i = 0; i < Size; i++) Data[i] = data[i];
		RefCount = 1;
	}

	template <typename T> Stringt<T>::StringData::StringData(const T *data, int size)
	{
		Size = size + 1;
		Data = new T[Size];
		for (int i = 0; i < size; i++) Data[i] = data[i];
		Data[size] = 0;
		RefCount = 1;
	}

	template <typename T> Stringt<T>::StringData::~StringData()
	{
		delete [] Data;
	}

	template <typename T> Stringt<T> operator +(const T *s1, const Stringt<T>& s2)
	{
		return Stringt<T>(s1) + s2;
	}

	template <typename T> Stringt<T> operator +(T c, const Stringt<T>& s)
	{
		return Stringt<T>(c) + s;
	}

	template <typename T> Stringt<T> operator +(long long l, const Stringt<T>& s)
	{
		return Stringt<T>(l) + s;
	}

	template <typename T> Stringt<T> operator +(int i, const Stringt<T>& s)
	{
		return Stringt<T>(i) + s;
	}

	template <typename T> Stringt<T> operator +(short s, const Stringt<T>& s2)
	{
		return Stringt<T>(s) + s2;
	}

	template <typename T> Stringt<T> operator +(float f, const Stringt<T>& s)
	{
		return Stringt<T>(f) + s;
	}

	template <typename T> Stringt<T> operator +(double d, const Stringt<T>& s)
	{
		return Stringt<T>(d) + s;
	}
}

#endif

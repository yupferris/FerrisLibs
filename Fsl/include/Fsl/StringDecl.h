#ifndef __FSL_STRINGDECL_H__
#define __FSL_STRINGDECL_H__

namespace Fsl
{
	template <typename T> class List;

	template <typename T> class Stringt
	{
	public:
		Stringt();
		Stringt(const Stringt& s);
		Stringt(const T *s);
		Stringt(T c);
		Stringt(long long l);
		Stringt(int i);
		Stringt(float f, int decimalPlaces = 6);
		Stringt(double d, int decimalPlaces = 6);
		~Stringt();

		Stringt& operator =(const Stringt& s);
		Stringt& operator =(const T *s);

		void Clear();

		int Length() const;

		T& Get(int index);
		T& operator [](int index);
		const T& Get(int index) const;
		const T& operator [](int index) const;
		const T* GetData() const;

		bool operator ==(const Stringt& s) const;
		bool operator ==(const T *s) const;
		bool operator !=(const Stringt& s) const;
		bool operator !=(const T *s) const;

		Stringt operator +(const Stringt& s) const;
		Stringt operator +(const T* s) const;
		Stringt operator +(T c) const;
		Stringt operator +(long long l) const;
		Stringt operator +(int i) const;
		Stringt operator +(short s) const;
		Stringt operator +(float f) const;
		Stringt operator +(double d) const;
		Stringt& operator +=(const Stringt& s);
		Stringt& operator +=(const T* s);
		Stringt& operator +=(T c);
		Stringt& operator +=(long long l);
		Stringt& operator +=(int i);
		Stringt& operator +=(short s);
		Stringt& operator +=(float f);
		Stringt& operator +=(double d);

		bool StartsWith(T c) const;
		bool StartsWith(const Stringt& s) const;
		bool EndsWith(T c) const;
		bool EndsWith(const Stringt& s) const;
		Stringt Substring(int startPos) const;
		Stringt Substring(int startPos, int len) const;
		int LastIndexOf(T c) const;
		List<Stringt> Split(T c) const;
		Stringt ToLower() const;
		Stringt Trim() const;

		bool TryParseInt(int& value) const;

	private:
		static bool isWhitespace(T c);
		static bool isDigit(T c);

		void init(long long l);
		void init(double d, int decimalPlaces);

		void ensureUniqueStringData();

		class StringData
		{
		public:
			T *Data;
			int Size;
			int RefCount;

			StringData(const T *data);
			StringData(const T *data, int size);
			~StringData();
		};

		StringData *stringData;
	};

	template <typename T> Stringt<T> operator +(const T* s1, const Stringt<T>& s2);
	template <typename T> Stringt<T> operator +(T c, const Stringt<T>& s);
	template <typename T> Stringt<T> operator +(long long l, const Stringt<T>& s);
	template <typename T> Stringt<T> operator +(int i, const Stringt<T>& s);
	template <typename T> Stringt<T> operator +(float f, const Stringt<T>& s);
	template <typename T> Stringt<T> operator +(double d, const Stringt<T>& s);

	typedef Stringt<char> String;
}

#endif

#include <Fsl/Console.h>

#include <iostream>
#include <string>
using namespace std;

namespace Fsl
{
	void Console::Write(const String& s)
	{
		auto d = s.GetData();
		if (d) cout << d;
	}

	void Console::WriteLine(const String& s)
	{
		Write(s);
		cout << "\n";
	}

	char Console::ReadChar()
	{
		char c;
		cin >> c;
		return c;
	}

	int Console::ReadInt()
	{
		int i;
		cin >> i;
		return i;
	}

	float Console::ReadFloat()
	{
		float f;
		cin >> f;
		return f;
	}

	double Console::ReadDouble()
	{
		int d;
		cin >> d;
		return d;
	}

	String Console::ReadLine()
	{
		string s;
		getline(cin, s);
		return String(s.c_str());
	}
}

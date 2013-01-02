#include <Fsl/File.h>

#include <fstream>
using namespace std;

namespace Fsl
{
	String File::ReadAllText(const String& path)
	{
		ifstream inputFile(path.GetData());
		if (inputFile.fail()) throw FSL_EXCEPTION("Could not open input file: \"" + path + "\"");
		string inputString((istreambuf_iterator<char>(inputFile)), istreambuf_iterator<char>());
		inputFile.close();
		String ret(inputString.c_str());
		return ret;
	}

	void File::WriteAllText(const String& path, const String& text)
	{
		ofstream outputFile(path.GetData());
		if (outputFile.fail()) throw FSL_EXCEPTION("Could not open output file: \"" + path + "\"");
		auto textData = text.GetData();
		if (textData) outputFile << textData;
		outputFile.close();
	}

	List<unsigned char> File::ReadAllBytes(const String& path)
	{
		ifstream inputFile(path.GetData(), ios::binary | ios::ate);
		if (inputFile.fail()) throw FSL_EXCEPTION("Could not open input file: \"" + path + "\"");
		int length = (int) inputFile.tellg();
		inputFile.seekg(0);
		unsigned char *buf = new unsigned char[length];
		inputFile.read((char *)buf, length);
		inputFile.close();
		List<unsigned char> ret;
		for (int i = 0; i < length; i++) ret.Add(buf[i]);
		delete [] buf;
		return ret;
	}

	void File::WriteAllBytes(const String& path, const List<unsigned char>& bytes)
	{
		ofstream outputFile(path.GetData(), ios::binary);
		if (outputFile.fail()) throw FSL_EXCEPTION("Could not open output file: \"" + path + "\"");
		unsigned char *buf = new unsigned char[bytes.Count()];
		for (int i = 0; i < bytes.Count(); i++) buf[i] = bytes[i];
		outputFile.write((const char *)buf, bytes.Count());
		delete [] buf;
		outputFile.close();
	}
}
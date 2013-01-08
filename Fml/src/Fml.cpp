#include <Fml.h>

using namespace Fsl;

int main(int argc, char **argv)
{
	List<String> arguments;
	for (int i = 1; i < argc; i++) arguments.Add(argv[i]);
	return Main(arguments);
}

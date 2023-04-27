#include "Convert.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		return 0;
	Convert a(argv[1]);
	a.convert_all();
	return 0 ;
}

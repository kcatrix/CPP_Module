#include "Harl.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	Harl oHarl;
	std::string str;
	str = argv[1];
	if (str == "debug" || str == "info" || str == "warning" || str == "error")
		oHarl.complain(str);
	return (0);
}

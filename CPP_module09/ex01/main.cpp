#include "RPN.hpp"

int main(int ac, char** av)
{
	if (ac != 2 || av[1][0] == '\0')
	{
		std::cout << "Wrong number of Arguments" << std::endl;
		return 1;
	}
	std::string valeur(av[1]);
	RPN joe(valeur);
	return 0;
}

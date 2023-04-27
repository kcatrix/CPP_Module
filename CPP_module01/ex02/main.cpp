#include <iostream>

int	main()
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stri;
	std::string	&strin = str;

	stri = &str;
	std::cout << &str << std::endl;
	std::cout << stri << std::endl;
	std::cout << &strin << std::endl;
	std::cout << str << std::endl;
	std::cout << *stri << std::endl;
	std::cout << strin << std::endl;

}

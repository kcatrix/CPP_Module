#include <string>
#include <iomanip>
#include "Harl.hpp"

Harl::Harl( void )
{
	return;
}

Harl::~Harl( void )
{
	return;
}

void	Harl::complain(std::string level)
{
	void (Harl::*tabf[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string tab[] ={"debug", "info","warning", "error"};
	char c;
	if (level == "debug")
		c = 'd';
	if (level == "info")
		c = 'i';
	if (level == "warning")
		c = 'w';
	if (level == "error")
		c = 'e';
	switch(c)
	{
		case 'd':
		{
			for(int i = 0; i != 4; i++)
				(this->*tabf[i])();
			break ;
		}
		case 'i':
		{
			for(int i = 1; i != 4; i++)
				(this->*tabf[i])();
			break ;
		}
		case 'w':
		{
			for(int i = 2; i != 4; i++)
				(this->*tabf[i])();
			break ;
		}
		case 'e':
		{
			for(int i = 3; i != 4; i++)
				(this->*tabf[i])();
			break ;
		}

	}
}

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "fonction debug" << std::endl;
	std::cout << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "fonction info" << std::endl;
	std::cout << std::endl;

}

void	Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "fonction warning" << std::endl;
	std::cout << std::endl;

}

void	Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "fonction error" << std::endl;
	std::cout << std::endl;
}

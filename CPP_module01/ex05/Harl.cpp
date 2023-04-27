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
	for (int i = 0; i < 4; i++)
	{
		if (level == tab[i])
			(this->*tabf[i])();
	}
}

void	Harl::debug(void)
{
	std::cout << "fonction debug" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "fonction info" << std::endl;

}

void	Harl::warning(void)
{
	std::cout << "fonction warning" << std::endl;

}

void	Harl::error(void)
{
	std::cout << "fonction error" << std::endl;
}

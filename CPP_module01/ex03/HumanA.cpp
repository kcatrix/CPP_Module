#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA( void ) : A(*(new Weapon())), name( "poney" )
{
}

HumanA::HumanA( std::string const & name, Weapon const & A ) : A(A), name(name)
{
}

HumanA::HumanA( HumanA const & HumanA ) : A(HumanA.A), name(HumanA.name)
{
}

HumanA::~HumanA( void )
{
}

void	HumanA::attack( void ) const
{
	std::cout << this->name << " attacks with their weapon " << this->A.getType();
	std::cout << std::endl;
	return;
}

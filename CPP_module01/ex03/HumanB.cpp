#include "HumanB.hpp"

HumanB::HumanB(std::string const & name) : _B(NULL), _name(name){}

HumanB::~HumanB( void )
{
	return;
}

void	HumanB::attack( void ) const
{
	std::cout << this->_name << " attacks with their weapon " << this->_B->getType();
	std::cout << std::endl;
	return;
}

void	HumanB::setWeapon( Weapon const & _B )
{
	this->_B = &_B;
	return;
}

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _Hit_points(10), _Energy_points(10), _Attack_damage(0)
{
	this->_name = name;
	std::cout << "constucteur called" << std::endl;
	return;
}
ClapTrap::~ClapTrap( void )
{
	std::cout << "destructeur  called" << std::endl;
	return;
}


void ClapTrap::attack(const std::string& target)
{
	if ( this->_Hit_points > 0 && this->_Energy_points > 0)
	{
		std::cout << "ClapTrap " <<  this->_name << " attack " << target << ", causing " << this->_Attack_damage << 
		" point of damage" <<  std::endl;
		this->_Energy_points--;
	}
	else
		return ;	
}
void ClapTrap::takeDamage(unsigned int amount)
{
	if ( this->_Hit_points > 0 && this->_Energy_points > 0)
	{
		std::cout << "ClapTrap " <<  this->_name << " take " << amount << 
		" point of damage" <<  std::endl;
		this->_Hit_points -= amount;
	}		
	else 
		return ;
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if ( this->_Hit_points > 0 && this->_Energy_points > 0)
	{
		std::cout << "ClapTrap " <<  this->_name << " repair " << amount << 
		" point of damage" <<  std::endl;
		this->_Energy_points--;
		this->_Hit_points += amount;
	}
	else
		return ;	
		
}


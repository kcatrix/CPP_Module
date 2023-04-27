#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void )
{
	std::cout << "constucteur  called" << std::endl;
	return;
}

ClapTrap::ClapTrap(std::string name) : Hit_points(100), Energy_points(50), Attack_damage(20)
{
	this->name = name;
	std::cout << "constucteur called" << std::endl;
	return;
}

ClapTrap::ClapTrap( ClapTrap const & )
{
	return ;
}

ClapTrap & ClapTrap::operator=( ClapTrap const & cp)
{
	this->Attack_damage = cp.Attack_damage;
	this->Hit_points = cp.Hit_points;
	this->Energy_points = cp.Energy_points;
	this->name = cp.name;
	return *this;
}

ClapTrap::~ClapTrap( void )
{
	std::cout << "destructeur  called" << std::endl;
	return;
}

void ClapTrap::attack(const std::string& target)
{
	if ( this->Hit_points > 0 && this->Energy_points > 0)
	{
		std::cout << "ClapTrap " <<  this->name << " attack " << target << ", causing " << this->Attack_damage << 
		" point of damage" <<  std::endl;
		this->Energy_points--;
	}
	else
		return ;	
}
void ClapTrap::takeDamage(unsigned int amount)
{
	if ( this->Hit_points > 0 && this->Energy_points > 0)
	{
		std::cout << "ClapTrap " <<  this->name << " take " << amount << 
		" point of damage" <<  std::endl;
		this->Hit_points -= amount;
	}		
	else 
		return ;
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if ( this->Hit_points > 0 && this->Energy_points > 0)
	{
		std::cout << "ClapTrap " <<  this->name << " repair " << amount << 
		" point of damage" <<  std::endl;
		this->Energy_points--;
		this->Hit_points += amount;
	}
	else
		return ;	
		
}


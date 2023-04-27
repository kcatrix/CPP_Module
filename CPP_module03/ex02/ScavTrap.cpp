#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void )
{
        std::cout << "constucteur Scav called" << std::endl;
        return;
}


ScavTrap::ScavTrap(std::string name) : ClapTrap::ClapTrap(name)
{
	std::cout << "constucteur Scav called" << std::endl;
	return;
}

ScavTrap::ScavTrap( ScavTrap const & )
{
        return;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & cp)
{
        this->Attack_damage = cp.Attack_damage;
        this->Hit_points = cp.Hit_points;
        this->Energy_points = cp.Energy_points;
        this->name = cp.name;
	return *this;
}

ScavTrap::~ScavTrap( void )
{
	std::cout << "destructeur Scav called" << std::endl;
	return;
}

void ScavTrap::attack(const std::string& target)
{
	if ( this->Hit_points > 0 && this->Energy_points > 0)
	{
		std::cout << "ScavTrap " <<  this->name << " attack " << target << ", causing " << this->Attack_damage << 
		" point of damage" <<  std::endl;
		this->Energy_points--;
	}
	else
		return ;	
}

void ScavTrap::guardGate( void )
{
	std::cout << "------- Gate Keeper mode Activated ---------" << std::endl;
}

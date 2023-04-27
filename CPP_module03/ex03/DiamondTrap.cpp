#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void )
{
        std::cout << "constucteur Diamond called" << std::endl;
        return;
}


DiamondTrap::DiamondTrap(std::string name) : ScavTrap::ScavTrap(name)
{
	std::cout << "constucteur Diamond called" << std::endl;
	return;
}

DiamondTrap::DiamondTrap( DiamondTrap const & )
{
        return;
}

DiamondTrap & DiamondTrap::operator=(DiamondTrap const & cp)
{
        this->Attack_damage = cp.Attack_damage;
        this->Hit_points = cp.Hit_points;
        this->Energy_points = cp.Energy_points;
        this->name = cp.name;
	return *this;
}

DiamondTrap::~DiamondTrap( void )
{
	std::cout << "destructeur Diamond called" << std::endl;
	return;
}

void DiamondTrap::attack(const std::string& target)
{
	if ( this->Hit_points > 0 && this->Energy_points > 0)
	{
		std::cout << "DiamondTrap " <<  this->name << " attack " << target << ", causing " << this->Attack_damage <<
		" point of damage" <<  std::endl;
		this->Energy_points--;
	}
	else
		return ;
}

void DiamondTrap::whoAmI( void )
{
	std::cout << this->name << "&&" << ClapTrap.name << std::endl;
}

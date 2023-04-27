#include "FragTrap.hpp"

FragTrap::FragTrap( void )
{
        std::cout << "constucteur Frag called" << std::endl;
        return;
}


FragTrap::FragTrap(std::string name) : ClapTrap::ClapTrap(name)
{
	std::cout << "constucteur Frag called" << std::endl;
	Hit_points = 100, Energy_points = 100, Attack_damage = 30;
	return;
}

FragTrap::FragTrap( FragTrap const & )
{
        return;
}

FragTrap & FragTrap::operator=(FragTrap const & cp)
{
        this->Attack_damage = cp.Attack_damage;
        this->Hit_points = cp.Hit_points;
        this->Energy_points = cp.Energy_points;
        this->name = cp.name;
	return *this;
}

FragTrap::~FragTrap( void )
{
	std::cout << "destructeur Frag called" << std::endl;
	return;
}

void FragTrap::attack(const std::string& target)
{
	if ( this->Hit_points > 0 && this->Energy_points > 0)
	{
		std::cout << "FragTrap " <<  this->name << " attack " << target << ", causing " << this->Attack_damage <<
		" point of damage" <<  std::endl;
		this->Energy_points--;
	}
	else
		return ;
}

void FragTrap::highFiveGuys( void )
{
	std::cout << "------ High Fives Demands in progress ------" << std::endl;
}

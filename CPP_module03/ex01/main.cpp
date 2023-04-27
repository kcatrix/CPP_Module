#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main()
{
	ClapTrap jean("jean");
	ScavTrap Bernard("bernard");
	jean.takeDamage(5);
	Bernard.guardGate( );
	Bernard.takeDamage(5);
	Bernard.attack("chichi");
	Bernard.beRepaired(10);
}

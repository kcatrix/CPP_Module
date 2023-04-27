#include "ClapTrap.hpp"

int	main()
{
	ClapTrap Paolo("Paolo");
	Paolo.attack("jean claude");
	Paolo.takeDamage(5);
	Paolo.beRepaired(5);
	Paolo.takeDamage(5);
	Paolo.takeDamage(5);
	Paolo.attack("jean claude");
}

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main()
{
	ClapTrap jean( "jean" );
	ScavTrap josette( "josette" );
	FragTrap Bernard( "bernard" );
	jean.takeDamage( 5 );
	josette.takeDamage( 5 );
	Bernard.highFiveGuys( );
	josette.guardGate( );
	Bernard.takeDamage( 5 );
	josette.takeDamage( 50 );
	Bernard.attack( "chichi" );
	josette.attack( "mimi mathy" );
	Bernard.beRepaired( 10 );
	josette.beRepaired( 2 );
}

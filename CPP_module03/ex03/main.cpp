#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main()
{
	ClapTrap jean( "jean" );
	ScavTrap josette( "josette" );
	FragTrap Bernard( "bernard" );
	DiamondTrap Polina( "Polina" );
	jean.takeDamage( 5 );
	josette.takeDamage( 5 );
	Polina.takeDamage( 5 );
	Bernard.highFiveGuys( );
	josette.guardGate( );
	Polina.highFiveGuys( );
	Polina.guardGate( );
	Polina.whoAmI( );
	Bernard.takeDamage( 5 );
	josette.takeDamage( 50 );
	Polina.takeDamage( 20 );
	Bernard.attack( "chichi" );
	josette.attack( "mimi mathy" );
	Polina.attack( "Le président" );
	Bernard.beRepaired( 10 );
	josette.beRepaired( 2 );
	Polina.beRepaired( 6 );
}

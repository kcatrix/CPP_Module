#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# include <string>
# include <iostream>
//# include "ScavTrap.hpp"

class ClapTrap
{
	public :
		ClapTrap( void );
		ClapTrap( ClapTrap const & ref);
		ClapTrap & operator=( ClapTrap const & egal );
		ClapTrap(std::string name);
		~ClapTrap( void );
		
		std::string name;
		int Hit_points;
		int Energy_points;
		int Attack_damage;

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

};

#endif

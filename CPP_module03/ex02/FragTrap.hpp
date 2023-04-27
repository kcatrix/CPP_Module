#ifndef FRAGTRAP_H
# define FRAGTRAP_H

# include <string>
# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public :
		FragTrap( void );
		FragTrap( FragTrap const &);
        	FragTrap& operator=(FragTrap const &);
                FragTrap(std::string name);
                ~FragTrap( void );

		int Hit_points;
		int Energy_points;
		int Attack_damage;
		void attack(const std::string& target);
		void highFiveGuys( void );

};

#endif

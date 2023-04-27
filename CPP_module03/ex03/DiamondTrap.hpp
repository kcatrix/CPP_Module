#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H

# include <string>
# include <iostream>
# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
        public :
                DiamondTrap( void );
                DiamondTrap( DiamondTrap const &);
                DiamondTrap& operator=(DiamondTrap const &);
                DiamondTrap(std::string name);
                ~DiamondTrap( void );

		void	whoAmI( void );

	private :
		std::string name;
};

#endif

#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# include <string>
# include <iostream>

class ClapTrap
{
	public :
		ClapTrap(std::string name);
		~ClapTrap( void );
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
	private :
		std::string _name;
		int _Hit_points;
		int _Energy_points;
		int _Attack_damage;
};

#endif

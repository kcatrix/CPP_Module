#ifndef HUMANB_H
# define HUMANB_H
# include <string>
# include <iostream>
# include "Weapon.hpp"

class HumanB
{
	public :
	void	attack( void ) const ;
	void	setWeapon( Weapon const & B );


	HumanB( std::string const & name );
	~HumanB( void );

	private:
		Weapon const * _B;
		std::string  _name;
		
};

#endif

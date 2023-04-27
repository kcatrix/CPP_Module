#ifndef HUMANA_H
# define HUMANA_H
# include <string>
# include "Weapon.hpp"

class HumanA
{
	public :
	void	attack( void ) const;

	Weapon const & A ;
	std::string name;

	HumanA( void ); 
	HumanA( HumanA const & HumanA ); 
	HumanA( std::string const & name, Weapon const & A );
	~HumanA( void );
};

#endif

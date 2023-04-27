#ifndef WEAPON_H
# define WEAPON_H
# include <string>

class Weapon
{
	public :
	std::string const 	&getType( void ) const;
	void		setType( std::string const & type );

	Weapon( void );
	Weapon( std::string const & type );
	Weapon( Weapon const & W );
	~Weapon( void );

	private :
	std::string _type;
};

#endif

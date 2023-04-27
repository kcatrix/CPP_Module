#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon( void ) : _type("brioche")
{
}

Weapon::Weapon( std::string const & type ) : _type(type)
{
}

Weapon::Weapon( Weapon const & W ) : _type(W._type)
{
}

Weapon::~Weapon( void )
{
}

std::string const	&Weapon::getType( void ) const
{
	return this->_type;
}

void		Weapon::setType( std::string const & type )
{
	this->_type = type;
	return;
}

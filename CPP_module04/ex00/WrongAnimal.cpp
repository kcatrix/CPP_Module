#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) : type("WrongAnimal") 
{
	std::cout << "Constructor called" << std::endl;
	return;
}

WrongAnimal::WrongAnimal( WrongAnimal const & )
{
	return;
}

WrongAnimal const & WrongAnimal::operator=( WrongAnimal const & cp )
{
	this->type = cp.type;
	return *this;
}

WrongAnimal::~WrongAnimal( void )
{
	std::cout << "Destructor called" << std::endl;
	return;
}

std::string const WrongAnimal::getType( void ) const
{
	return ( this->type );
}

void	WrongAnimal::setType( std::string type)
{
	this->type = type;
	return;
}

void WrongAnimal::makeSound( void ) const
{
	std::cout << "Au revoir" << std::endl;
}

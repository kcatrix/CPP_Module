#include "Animal.hpp"

Animal::Animal( void ) : type("Animal") 
{
	std::cout << "Constructor called" << std::endl;
	return;
}

Animal::Animal( Animal const & )
{
	return;
}

Animal const & Animal::operator=( Animal const & cp )
{
	this->type = cp.type;
	return *this;
}

Animal::~Animal( void )
{
	std::cout << "Destructor called" << std::endl;
	return;
}

std::string const Animal::getType( void ) const
{
	return ( this->type );
}

void	Animal::setType( std::string type)
{
	this->type = type;
	return;
}

void Animal::makeSound( void ) const
{
	std::cout << "Bonjour" << std::endl;
}

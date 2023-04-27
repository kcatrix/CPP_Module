#include "Dog.hpp"

Dog::Dog( void )
{
	this->type = "Dog";
	std::cout << "Constructor called" << std::endl;
	return;
}

Dog::Dog( Dog const & )
{
	return;
}

Dog const & Dog::operator=( Dog const & cp )
{
	this->type = cp.type;
	return *this;
}

Dog::~Dog( void )
{
	std::cout << "Destructor called" << std::endl;
	return;
}

void	Dog::makeSound( void ) const
{
	std::cout << "Waff" << std::endl;
	return;
}

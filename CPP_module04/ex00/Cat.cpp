#include "Cat.hpp"

Cat::Cat( void )
{
	this->type = "Cat";
	std::cout << "Constructor called" << std::endl;
	return;
}

Cat::Cat( Cat const & )
{
	return;
}

Cat const & Cat::operator=( Cat const & cp )
{
	this->type = cp.type;
	return *this;
}

Cat::~Cat( void )
{
	std::cout << "Destructor called" << std::endl;
	return;
}

void	Cat::makeSound( void ) const
{
	std::cout << "Miaou" << std::endl;
	return;
}

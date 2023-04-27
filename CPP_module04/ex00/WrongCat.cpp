#include "WrongCat.hpp"

WrongCat::WrongCat( void )
{
	this->type = "WrongCat";
	std::cout << "Constructor called" << std::endl;
	return;
}

WrongCat::WrongCat( WrongCat const & )
{
	return;
}

WrongCat const & WrongCat::operator=( WrongCat const & cp )
{
	this->type = cp.type;
	return *this;
}

WrongCat::~WrongCat( void )
{
	std::cout << "Destructor called" << std::endl;
	return;
}

void	WrongCat::makeSound( void ) const
{
	std::cout << "Faux miaou" << std::endl;
}

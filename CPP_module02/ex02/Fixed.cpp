#include "Fixed.hpp"

Fixed::Fixed() : _number(0)
{
	return;
}

Fixed::Fixed(int const int_value)
{
	this->_number = int_value << this->_bits;
	return;
}

Fixed::Fixed(float const float_value)
{
	this->_number = roundf(float_value * (1 << this->_bits));
	return;
}

Fixed::Fixed(const Fixed &src)
{
	*this = src;
	return;
}

Fixed::~Fixed()
{
	return;
}

void	Fixed::setRawBits(const int raw)
{
	this->_number = raw;
	return;
}

int Fixed::getRawBits() const
{
	return (this->_number);
}

float	Fixed::toFloat() const
{
	return ((float) this->_number / (1 << this->_bits));
}

int	Fixed::toInt() const
{
	return (this->_number >> this->_bits);
}

Fixed &Fixed::operator=(const Fixed &rhs)
{
	this->_number = rhs.getRawBits();
	return (*this);
}

bool Fixed::operator<(const Fixed &rhs) const
{
	return (this->_number < rhs._number);
}

bool Fixed::operator>(const Fixed &rhs) const
{
	return (this->_number > rhs._number);
}

bool Fixed::operator<=(const Fixed &rhs) const
{
	return (this->_number <= rhs._number);
}

bool Fixed::operator>=(const Fixed &rhs) const
{
	return (this->_number >= rhs._number);
}

bool Fixed::operator==(const Fixed &rhs) const
{
	return (this->_number == rhs._number);
}

bool Fixed::operator!=(const Fixed &rhs) const
{
	return (this->_number != rhs._number);
}

Fixed	Fixed::operator+(const Fixed &rhs)
{
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed	Fixed::operator-(const Fixed &rhs)
{
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed	Fixed::operator*(const Fixed &rhs)
{
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed	Fixed::operator/(const Fixed &rhs)
{
	return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed &	Fixed::operator++()
{
	++this->_number;
	return (*this);
}

Fixed &	Fixed::operator--()
{
	--this->_number;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	old = *this;
	operator++();	
	return old;	
}

Fixed	Fixed::operator--(int)
{
	Fixed	old = *this; 
	operator--();	
	return old;		
}

std::ostream &	operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return (o);
}

Fixed	Fixed::min(Fixed &value1, Fixed &value2)
{
	if (value1 < value2)
		return (value1);
	else
		return (value2);
}

Fixed	Fixed::min(const Fixed &value1, const Fixed &value2)
{
	if (value1 < value2)
		return (value1);
	else
		return (value2);
}

Fixed	Fixed::max(Fixed &value1, Fixed &value2)
{
	if (value1 > value2)
		return (value1);
	else
		return (value2);
}

Fixed	Fixed::max(const Fixed &value1, const Fixed &value2)
{
	if (value1 > value2)
		return (value1);
	else
		return (value2);
}

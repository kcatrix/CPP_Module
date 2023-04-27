/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 13:41:03 by juan              #+#    #+#             */
/*   Updated: 2022/05/16 12:07:29 by jbuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits>
#include "Convert.hpp"

Convert::Convert( void )
{
	std::cout << "Constructor called" << std::endl;
	return;
}
Convert::Convert( char * val ) : _val(val),  _temp(_val)
{
	std::cout << "Constructor called" << std::endl;
	return ;
}

Convert::Convert( Convert const & )
{
	return ;
}

Convert & Convert::operator=( Convert const & cp )
{
	this->_val = cp._val; 
	return *this;
}

void Convert::convert_all( void )
{
	if (_temp == "nan" || _temp == "-inf" || _temp == "+inf" || _temp == "inf" || _temp == "+inff" || _temp == "-inff" || _temp == "nanf")
	{
		std::cout << "char = impossible"<<  std::endl;	
		std::cout << "int  = impossible"<<  std::endl;
		if (_temp == "nan" || _temp == "nanf")
		{	
			std::cout << "float = nanf"<<  std::endl;	
			std::cout << "double = nan"<<  std::endl;	
		} 	
		else if (_temp == "-inf" || _temp == "-inff")
		{
			std::cout << "float = -inff"<<  std::endl;	
			std::cout << "double = -inf"<<  std::endl;
		}
		else if (_temp == "+inf" || _temp == "+inff" || _temp == "inf")
		{
			std::cout << "float = inff"<<  std::endl;	
			std::cout << "double = inf"<<  std::endl;
		}
		return ;
	}	
	double d;
	if ( strlen(_val) == 1 )
		d = _val[0] - 48;
	else if ( strlen(_val) == 3 && _val[0] == 39 && _val[2] == 39 )
		d = _val[1];
	else
		d = atof(_val);
	float c;
	c = static_cast<float>(d);
	int b;
	b = static_cast<int>(d);
	int i;	
	i = 0;
	/*std::cout << "strlen: " << strlen(_val) << std::endl;
	while (_val[i])
	{
		std::cout << _val[i] << " && " << i << std::endl;
		i++;
	}
	std::cout << "val = " << this->_val << std::endl;*/
	// gérer les overflow ? 	
	if ( b > 32 && b < 127 )
		std::cout << "char: '" << static_cast<char>(b) << "'" <<  std::endl;
	else if (( b >= 0 && b <= 32) || b == 127)
		std::cout << "char: non displayable" << std::endl;
	else if (b < 0 || b > 127)
		std::cout << "char: impossible" << std::endl;
	if ( b >= std::numeric_limits<int>::min() && b <= std::numeric_limits<int>::max() )
		std::cout << "int : " << b << std::endl;
	else
		std::cout << "int : impossible" << std::endl;
	if ( c == b )
	std::cout << "float: " << c << ".0f" <<  std::endl;
	else 
	std::cout << "float: " << c << "f" <<  std::endl;
	if ( c == d )
	std::cout << "double: " << d << ".0" << std::endl;
	else
	std::cout << "double: " << d << std::endl;
	}

Convert::~Convert( void )
{
	std::cout << "Destructor called" << std::endl;
	return;
}


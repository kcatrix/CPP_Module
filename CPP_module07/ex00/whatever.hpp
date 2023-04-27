#ifndef WHATEVER_HPP
# define WHATEVER_HPP
# include <string>
# include <iostream>

template< typename T >
T const & max( T const & x, T const & y )
{
	return ( x > y ? x : y );
}

template< typename T >
T const & min( T const & x, T const & y )
{
	return ( x < y ? x : y );
}

template< typename T >
void swap( T & x, T & y )
{
	T plot;

	plot = x;
	x = y;
	y = plot;
}

#endif
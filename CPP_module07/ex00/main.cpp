#include "whatever.hpp"

int	main( )
{
	/*
	int a = 10;
	int b = 5;

	std::cout << "Nous avons a = " << a << " & b = " << b << std::endl;
	std::cout << "Le plus grand est : " << ::max( a, b ) << std::endl;
	std::cout << "Le plus petit est : " << ::min( a, b ) << std::endl;
	::swap( a, b );
	std::cout << "Soudainement, a = " << a  << " et b = " << b << std::endl;
	std::cout << std::endl;


	float c = 5.35;
	float d = 5.35;

	std::cout << "Nous avons c = " << c << " & d = " << d << std::endl;
	std::cout << "Le plus grand est : " << ::max( c, d ) << std::endl;
	std::cout << "Le plus petit est : " << ::min( c, d ) << std::endl;
	::swap( c, d );
	std::cout << "Soudainement, c = " << c  << " et d = " << d << std::endl;
	std::cout << std::endl;

	char e = 'h';
	char f = 'p';

	std::cout << "Nous avons e = " << e << " & f = " << f << std::endl;
	std::cout << "Le plus grand est : " << ::max( e, f ) << std::endl;
	std::cout << "Le plus petit est : " << ::min( e, f ) << std::endl;
	::swap( e, f );
	std::cout << "Soudainement, e = " << e  << " et f = " << f << std::endl;
	std::cout << std::endl;

	std::string g = "Enculux";
	std::string h = "Enculou";

	std::cout << "Nous avons g = " << g << " & h = " << h << std::endl;
	std::cout << "Le plus grand est : " << ::max( g, h ) << std::endl;
	std::cout << "Le plus petit est : " << ::min( g, h ) << std::endl;
	::swap( g, h );
	std::cout << "Soudainement, g = " << g  << " et h = " << h << std::endl;
	std::cout << std::endl;*/

	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
}

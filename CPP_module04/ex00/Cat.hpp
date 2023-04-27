#ifndef CAT_HPP
# define CAT_HPP
# include <string>
# include <iostream>
# include "Animal.hpp" 

class Cat : public Animal
{
	public :
		Cat( void );
		Cat( Cat const & ref);
		Cat const & operator=( Cat const & egal );
		~Cat( void );

		virtual void makeSound( void ) const;
};

#endif

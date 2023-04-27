#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <string>
# include <iostream>

class Animal
{
	public:
		Animal( void );
		Animal( Animal const & cp );
		Animal const & operator=( Animal const & cp);
		virtual ~Animal( void );

		virtual void makeSound( void ) const;
		void setType( std::string type );
		std::string const getType( void ) const;

	protected:
		std::string type;
};

#endif


#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <string>
# include <iostream>

class WrongAnimal
{
	public:
		WrongAnimal( void );
		WrongAnimal( WrongAnimal const & cp );
		WrongAnimal const & operator=( WrongAnimal const & cp);
		~WrongAnimal( void );

		void makeSound( void ) const;
		void setType( std::string type );
		std::string const getType( void ) const;

	protected:
		std::string type;
};

#endif

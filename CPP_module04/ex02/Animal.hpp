#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{
	public:
		// Constructors
		Animal();
		Animal(const Animal &copy);
		Animal(std::string type);
		
		// Destructor
		virtual ~Animal();

		// Operators
		Animal & operator=(const Animal &assign);
		
		// Getters / Setters
		virtual std::string getType() const;

		virtual void	makeSound( void ) const = 0;
		
	protected:
		std::string _type;
		
};

#endif
#include "Dog.hpp"
#include "Brain.hpp"

// Constructors
Dog::Dog() : Animal("Dog")
{
	std::cout << "\e[0;33mDefault Constructor called of Dog\e[0m" << std::endl;
	_brain = new Brain();
}

Dog::Dog(const Dog &copy)
{
	std::cout << "\e[0;33mCopy Constructor called of Dog\e[0m" << std::endl;
	_brain = new Brain(*copy._brain);
}


// Destructor
Dog::~Dog()
{
	delete _brain;
	std::cout << "\e[0;31mDestructor called of Dog\e[0m" << std::endl;
}


// Operators
Dog & Dog::operator=(const Dog &assign)
{
	_brain = new Brain(*assign._brain);
	_type = assign._type;
	return *this;
}

void	Dog::makeSound( void ) const
{
	std::cout << "Bork! "  + _type << std::endl;
}

void	Dog::addIdea(std::string idea)
{
	_brain->ideas[_brain->idea_count] = idea;
	_brain->idea_count++;
}

void	Dog::getIdeas( void )
{
	int i;

	i = -1;
	while (++i <= _brain->idea_count)
		std::cout << _brain->ideas[i] << std::endl;
}
#include "Brain.hpp"

// Constructors
Brain::Brain()
{
	idea_count = 0;
	std::cout << "\e[0;33mDefault Constructor called of Brain\e[0m" << std::endl;
}

Brain::Brain(const Brain &copy)
{
    // Copy the elements of the source array to the destination array
	idea_count = copy.idea_count;
    std::memcpy(ideas, copy.ideas, sizeof(ideas));
	std::cout << "\e[0;33mCopy Constructor called of Brain\e[0m" << std::endl;
}


// Destructor
Brain::~Brain()
{
	std::cout << "\e[0;31mDestructor called of Brain\e[0m" << std::endl;
}


// Operators
Brain & Brain::operator=(const Brain &assign)
{
	idea_count = assign.idea_count;
	std::memcpy(ideas, assign.ideas, sizeof(ideas));
	return *this;
}


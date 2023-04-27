#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

void    testCreation( void )
{
    const Animal* j[10];
    int i;

    i = -1;
    while (i++ < 9)
    {
        if (i % 2)
            j[i] = new Cat();
        else
            j[i] = new Dog();
        j[i]->makeSound();
    }
    i = -1;
    while (i++ < 9)
    {
        delete j[i];
    }
    
    system ("leaks brain");
}


int main()
{
    Dog jack;
    Dog second;

    jack.makeSound();
    jack.addIdea("Eat bone");
    jack.addIdea("Eat homework");
    jack.addIdea("Eat carpet");
    jack.getIdeas();
    second = jack;
    jack.addIdea("Eat WRONG");
    second.getIdeas();
	std::cout << "-------------------------------------------" << "\n";
    jack.getIdeas();
	
	Dog basic;
	{
		Dog tmp = basic;
		basic.addIdea("Eat carpe");
		tmp.addIdea("Eat chicken");
		tmp.getIdeas();
	}
	basic.getIdeas();
    
}
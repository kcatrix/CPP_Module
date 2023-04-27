#include "Zombie.hpp"

int main()
{
    randomChump("thierry");
    Zombie *z = newZombie("Rober");
    z->announce();
    delete z;
    return (1); 
}
#include "Zombie.hpp"

int main()
{
    int n = 6;
    Zombie *h = zombieHorde(n, " ethan");

    for (int i = 0; i < n; i++)
        h[i].announce();
    delete[] h;
    return (1);
}
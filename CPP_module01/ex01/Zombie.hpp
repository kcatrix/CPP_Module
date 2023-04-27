#include <string>
#include <iostream>

class Zombie
{
    private:
        std::string name;
    public:
        void announce(void);
        void setName(std::string name);
        Zombie(std::string name);
        Zombie();
        ~Zombie();
};

Zombie *zombieHorde(int n, std::string name);
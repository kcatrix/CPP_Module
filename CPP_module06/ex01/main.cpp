#include "Convert.hpp"

uintptr_t serialize( Data * ptr )
{
	std::cout << "--------------serialize---------------" << std::endl;
	std::cout << ptr->i << std::endl;
	std::cout << ptr << std::endl;
	return( reinterpret_cast<uintptr_t>(ptr) );
}

Data * deserialize( uintptr_t raw )
{
	Data *a;
	a = reinterpret_cast<Data *>(raw);
	std::cout << "------------------------deserialize------------------" << std::endl;
	std::cout << a << std::endl;
	std::cout << a->i << std::endl;
	return (a);
}

int main()
{
	dd a;
	a.i = 123;
	std::cout << deserialize(serialize(&a)) << std::endl;
	std::cout << "-----------Ce bon vieux main-----------" << std::endl;
	std::cout << a.i << std::endl;
	return 0 ;
}

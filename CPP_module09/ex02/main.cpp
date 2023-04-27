#include "PmergeMe.hpp"


int main(int ac, char** av)
{
	if (parse(ac, av) == false)
		return (1);
	list<int> list;
	vector<int> arr;
	arr = getVector(ac, av);
	list = getlist(ac, av);
	std::cout << "Before: ";
	PrintVector(arr);
	PmergeMe pmergeMe(arr);
	PmergeMe pmergeMelist(list);
}

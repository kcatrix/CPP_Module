#include <iostream>
#include <stack>
#include <cstdlib>
#include <string.h>
#include <string>

class RPN
{
	public:
		RPN(std::string valeur);
		~RPN();
		int getSigne(std::string valeur);
		void split_ligne(std::string valeur);
	private:
		std::stack<int> stack;
};
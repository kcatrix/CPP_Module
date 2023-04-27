#include "RPN.hpp"

RPN::RPN(std::string valeur)
{
	split_ligne(valeur);
}

RPN::~RPN()
{
}

int RPN::getSigne(std::string valeur)
{
	int i = 0;
    while(valeur[i])
    {
        if((valeur[i] > '9' || valeur[i] < '0') && valeur[i] != '*' && valeur[i] != '/' && valeur[i] != '+' && valeur[i] != '-')
		{
			std::cout << "Error" << std::endl;
            exit(1);
		}
        i++;
    }
    if(i > 1)
    {
        std::cout << "Error" << std::endl;
        exit(1);
    }
    else
    {
        if (valeur == "*")
            return (2);
        else if (valeur == "/")
            return (3);
        else if (valeur == "+")
            return (4);
        else if (valeur == "-")
            return (5);
    }
    return 0;
}


void RPN::split_ligne(std::string valeur)
{
	int result = 0;
	int calcule = 0;
	int calcule2 = 0;
	char *token = strtok(const_cast<char *>(valeur.c_str()), " ");
	if (getSigne(token) == 0)
	{
		stack.push(atoi(token));
	}
	else
	{
		std::cout << "Error" << std::endl;
		exit(1);
	}
	while(token != NULL)
	{
		token = strtok(NULL, " ");
		if (token != NULL)
		{
			if (getSigne(token) == 0)
			{
				stack.push(atoi(token));
			}
			else if (getSigne(token) == 2)
			{
				if (stack.size() == 0)
				{
					std::cout << "Error" << std::endl;
					exit(1);
				}
				calcule2 = stack.top();
				stack.pop();
				if (stack.size() == 0)
				{
					std::cout << "Error" << std::endl;
					exit(1);
				}
				calcule = stack.top();
				stack.pop();
				if (!calcule)
					calcule = 0;
				result = calcule * calcule2;
				stack.push(result);
			}
			else if (getSigne(token) == 3)
			{
				if (stack.size() == 0)
				{
					std::cout << "Error" << std::endl;
					exit(1);
				}
				calcule2 = stack.top();
				stack.pop();
				if (stack.size() == 0)
				{
					std::cout << "Error" << std::endl;
					exit(1);
				}
				calcule = stack.top();
				stack.pop();
				if (calcule2 == 0)
				{
					std::cout << "Error: division par 0" << std::endl;
					exit(1);
				}
				result = calcule / calcule2;
				stack.push(result);
			}
			else if (getSigne(token) == 4)
			{
				if (stack.size() == 0)
				{
					std::cout << "Error" << std::endl;
					exit(1);
				}
				calcule2 = stack.top();
				stack.pop();
				if (stack.size() == 0)
				{
					std::cout << "Error" << std::endl;
					exit(1);
				}
				calcule = stack.top();
				stack.pop();
				result = calcule + calcule2;
				stack.push(result);
			}
			else if (getSigne(token) == 5)
			{
				if (stack.size() == 0)
				{
					std::cout << "Error" << std::endl;
					exit(1);
				}
				calcule2 = stack.top();
				stack.pop();
				if (stack.size() == 0)
				{
					std::cout << "Error" << std::endl;
					exit(1);
				}
				calcule = stack.top();
				stack.pop();
				if (!calcule)
                    calcule = 0;
				result = calcule - calcule2;
				stack.push(result);
			}
		}
	}
	if (stack.size() > 1)
	{
		std::cout << "Error" << std::endl;
		exit(1);
	}
	std::cout << stack.top() << std::endl;
}

#include <fstream>
#include <iostream>

int	main(int ac, char **av)
{
	if (ac == 4)
	{
		std::string filename( av[1] );
		filename += ".replace";
		std::ifstream ifile( av[1] );
		if (filename.find( av[1] ) == (size_t)-1)
		{
			std::cout << "It's an error for whatever reason" << std::endl;
			exit(-1);
		}
		std::ofstream ofile( filename );
		std::string str1( av[2] );
		std::string str2( av[3] );
		std::string str;
		char	c;
		int i;

		while ( ifile.get(c) )
			str += c;
		std::cout << str;
		i = str.find(str1);
		//std::cout << i << std::endl;
		while (i != -1)
		{
			str.erase( i, str1.size());
			str.insert( i, str2 );
			i = str.find(str1);
		}
		ofile << str;
	}
	else
	std::cout << "I'm disappointed" << std::endl;
}

#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <string>
# include <iostream>
# include <stdexcept>

class Convert
{
	public:
		Convert( void );
		Convert( char * val);
		Convert( Convert const & );
		~Convert( void );

		Convert & operator=( Convert const & cp);
		void convert_all( void );
	private:
		char * _val;
		std::string _temp;

};	

#endif

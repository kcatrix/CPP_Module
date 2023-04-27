#include <iostream>
#include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(int const int_value);
		Fixed(float const float_value);
		Fixed(const Fixed &src);
		~Fixed();

		Fixed &	operator=(const Fixed &rhs);

		bool	operator<(const Fixed &rhs) const;
		bool	operator>(const Fixed &rhs) const;
		bool	operator<=(const Fixed &rhs) const;
		bool	operator>=(const Fixed &rhs) const;
		bool	operator==(const Fixed &rhs) const;
		bool	operator!=(const Fixed &rhs) const;

		Fixed	operator+(const Fixed &rhs);
		Fixed	operator-(const Fixed &rhs);
		Fixed	operator*(const Fixed &rhs);
		Fixed	operator/(const Fixed &rhs);

		Fixed &	operator++(void); 
		Fixed & operator--(void);
		Fixed	operator++(int); 
		Fixed	operator--(int); 

		static Fixed	min(Fixed &value1, Fixed &value2);
		static Fixed	min(const Fixed &value1, const Fixed &value2);
		static Fixed	max(Fixed &value1, Fixed &value2);
		static Fixed	max(const Fixed &value1, const Fixed &value2);

		void	setRawBits(int const raw);
		int		getRawBits(void) const;

		float	toFloat(void) const;
		int		toInt(void) const;

	private:
		int					_number;
		static const int	_bits = 8;
};

std::ostream &	operator<<(std::ostream & o, Fixed const & rhs);

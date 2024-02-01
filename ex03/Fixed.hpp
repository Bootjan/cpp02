/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bootjan <bootjan@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/08 14:05:04 by bschaafs      #+#    #+#                 */
/*   Updated: 2024/01/11 16:41:27 by bschaafs      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <math.h>

# ifndef LOG
#  define LOG 1
# endif

class Fixed
{
	private:
		int					_value;
		static const int	_nBits = 8;
	public:
		// ### CON/DE STRUCTORS ###
		Fixed(void);
		Fixed(const int Int);
		Fixed(const float Float);
		Fixed(const Fixed &fixed);
		~Fixed();
		
		// ### MEMBER OPERATORS ###
		Fixed& 			operator=(const Fixed& original);
		Fixed			operator++(int);
		Fixed			operator--(int);
		Fixed			&operator--();
		Fixed			&operator++();

		// ### MIN/MAX ###
		static Fixed&		min(Fixed& fixed1, Fixed& fixed2);
		static const Fixed&	min(const Fixed& fixed1, const Fixed& fixed2);
		static Fixed&		max(Fixed& fixed1, Fixed& fixed2);
		static const Fixed&	max(const Fixed& fixed1, const Fixed& fixed2);

		// ### MEMBER FUNCTIONS ###
		int		getRawBits(void) const;
		void	setRawBits(const int raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

// ### NON MEMBER OPERATORS ##########################################

std::ostream&	operator<<(std::ostream& o, Fixed const& fixed);
bool			operator<(Fixed const& fixed1, Fixed const& fixed2);
bool			operator>(Fixed const& fixed1, Fixed const& fixed2);
bool			operator<=(Fixed const& fixed1, Fixed const& fixed2);
bool			operator>=(Fixed const& fixed1, Fixed const& fixed2);
bool			operator==(Fixed const& fixed1, Fixed const& fixed2);
bool			operator!=(Fixed const& fixed1, Fixed const& fixed2);
float			operator+(Fixed const& fixed1, Fixed const& fixed2);
float			operator-(Fixed const& fixed1, Fixed const& fixed2);
float			operator*(Fixed const& fixed1, Fixed const& fixed2);
float			operator/(Fixed const& fixed1, Fixed const& fixed2);

// ### HELPER FUNCTIONS ##############################################

#endif
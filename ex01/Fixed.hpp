/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bootjan <bootjan@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/08 14:05:04 by bschaafs      #+#    #+#                 */
/*   Updated: 2024/01/11 18:05:10 by bschaafs      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <math.h>

# ifndef OUTPUT
#  define OUTPUT 1
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
		
		// ### MEMBER FUNCTIONS ###
		Fixed& 			operator=(const Fixed& original);
		int				getRawBits(void) const;
		void			setRawBits(const int raw);
		float			toFloat(void) const;
		int				toInt(void) const;
};

std::ostream&	operator<<(std::ostream& o, Fixed const& fixed);

#endif
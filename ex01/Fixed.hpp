/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bootjan <bootjan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:05:04 by bschaafs          #+#    #+#             */
/*   Updated: 2024/01/11 11:46:10 by bootjan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

# ifndef OUTPUT
#  define OUTPUT 1
# endif

# define BIT_OFFSET 8

class Fixed
{
	private:
		int					_value;
		static const int	_nBits = 8;
	public:
		Fixed(void);
		Fixed(const int Int);
		Fixed(const float Float);
		Fixed(const Fixed &fixed);
		Fixed& 			operator=(const Fixed& original);
		~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(const int raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream&	operator<<(std::ostream& o, Fixed const& fixed);

#endif
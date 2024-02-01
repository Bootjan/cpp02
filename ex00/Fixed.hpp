/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bootjan <bootjan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:05:04 by bschaafs          #+#    #+#             */
/*   Updated: 2024/01/11 21:28:03 by bootjan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

# define BIT_OFFSET 8

# ifndef LOG
#  define LOG 1
# endif

class Fixed
{
	private:
		int					_value;
		static const int	_nBits = BIT_OFFSET;
	public:
		Fixed(void);
		Fixed(const Fixed &fixed);
		Fixed& operator=(const Fixed& original);
		~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(const int raw);
};

#endif
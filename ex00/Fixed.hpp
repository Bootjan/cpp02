/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bschaafs <bschaafs@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/08 14:05:04 by bschaafs      #+#    #+#                 */
/*   Updated: 2024/01/08 14:14:22 by bschaafs      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int					_value;
		static const int	_nBits = 8;
	public:
		Fixed(void);
		Fixed(Fixed &fixed);
		~Fixed();
		int	getRawBits(void) const;
};

#endif
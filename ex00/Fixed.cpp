/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bschaafs <bschaafs@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/08 14:04:52 by bschaafs      #+#    #+#                 */
/*   Updated: 2024/01/08 14:36:35 by bschaafs      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	this->_value = 0;
}

Fixed::~Fixed()
{
}

Fixed::Fixed(Fixed &fixed)
{
	this->_value = fixed._value;
}

int	Fixed::getRawBits(void) const
{
	return (this->_value);
}

void	Fixed::setRawBits(int rawBits)
{
	this->_value = rawBits;
}

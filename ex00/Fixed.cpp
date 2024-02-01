/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bootjan <bootjan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:04:52 by bschaafs          #+#    #+#             */
/*   Updated: 2024/01/11 21:28:52 by bootjan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

static void	print_message(const std::string msg)
{
	if (LOG)
		std::cout << msg << std::endl;
}

Fixed::Fixed(void)
{
	print_message("Default constructor called");
	this->_value = 0;
}

Fixed&	Fixed::operator=(const Fixed& original)
{
	print_message("Copy assignment operator called");
	this->_value = original.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	print_message("Destructor called");
}

Fixed::Fixed(const Fixed &fixed)
{
	print_message("Copy constructor called");
	this->_value = fixed._value;
}

int	Fixed::getRawBits(void) const
{
	print_message("getRawBits member function called");
	return (this->_value);
}

void	Fixed::setRawBits(const int raw)
{
	this->_value = raw;
}

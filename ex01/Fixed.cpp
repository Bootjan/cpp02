/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bootjan <bootjan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:04:52 by bschaafs          #+#    #+#             */
/*   Updated: 2024/01/11 11:46:53 by bootjan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const static float	dividers[] = { 0.5f, 0.25f, 0.125f, 0.0625f, \
0.03125f, 0.0156125f, 0.007806125f, 0.0039030625f};

static void	print_message(const std::string msg)
{
	std::cout << msg << std::endl;
}

Fixed::Fixed(void)
{
	print_message("Default constructor called");
	this->_value = 0;
}

Fixed::Fixed(const int Int)
{
	print_message("Int constructor called");
	this->_value = Int << BIT_OFFSET;
}

Fixed::Fixed(const float Float)
{
	print_message("Float constructor called");
	int		roundedInt = (int)floor(Float);
	float	decimals = Float - roundedInt;

	this->_value = roundedInt << BIT_OFFSET;
	for (int i = 1; i <= BIT_OFFSET; i++)
	{
		std::cout << "decimals: " << decimals << std::flush;
		std::cout << "	conditional: " << 0.5f / i << std::endl;
		if (decimals >= dividers[i - 1])
		{
			this->_value |= (1 << (BIT_OFFSET - i));
			decimals -= dividers[i - 1];
		}
	}
}

Fixed::~Fixed()
{
	print_message("Destructor called");
}

Fixed&	Fixed::operator=(const Fixed& original)
{
	print_message("Copy assignment operator called");
	this->_value = original.getRawBits();
	return (*this);
}

std::ostream&	operator<<(std::ostream& o, const Fixed& fixed)
{
	o << fixed.toFloat();
	return (o);
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

float	Fixed::toFloat(void) const
{
	int		Int = this->_value >> BIT_OFFSET;
	float	decimals = 0;

	for (int i = 1; i <= BIT_OFFSET; i++)
	{
		if (this->_value & (1 << (BIT_OFFSET - i)))
			decimals += dividers[i - 1];
	}
	return ((float)Int + decimals);
}

int		Fixed::toInt(void) const
{
	return (this->_value >> BIT_OFFSET);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bootjan <bootjan@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/08 14:04:52 by bschaafs      #+#    #+#                 */
/*   Updated: 2024/01/11 18:05:47 by bschaafs      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

static void	print_message(const std::string msg);

// #############################################################################
// 		CON/DE STRUCTORS
// #############################################################################

Fixed::Fixed(void)
{
	print_message("Default constructor called");
	this->_value = 0;
}

Fixed::Fixed(const int Int)
{
	print_message("Int constructor called");
	this->_value = Int << this->_nBits;
}

Fixed::Fixed(const float Float)
{
	print_message("Float constructor called");
	this->_value = std::roundf(Float * (1 << this->_nBits));
}

Fixed::~Fixed()
{
	print_message("Destructor called");
}


// #############################################################################
// 		MEMBER FUNCTIONS
// #############################################################################

Fixed&	Fixed::operator=(const Fixed& original)
{
	print_message("Copy assignment operator called");
	if (this != &original)
		this->_value = original.getRawBits();
	return (*this);
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
	return static_cast<float>(this->getRawBits()) / (1 << this->_nBits);
}

int		Fixed::toInt(void) const
{
	return (this->_value >> this->_nBits);
}


// #############################################################################
// 		NON MEMBER FUNCTIONS
// #############################################################################

std::ostream&	operator<<(std::ostream& o, const Fixed& fixed)
{
	o << fixed.toFloat();
	return (o);
}


// #############################################################################
// 		HELPER FUNCTIONS
// #############################################################################

static void	print_message(const std::string msg)
{
	std::cout << msg << std::endl;
}

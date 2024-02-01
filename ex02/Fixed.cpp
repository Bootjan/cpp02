/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bootjan <bootjan@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/08 14:04:52 by bschaafs      #+#    #+#                 */
/*   Updated: 2024/01/11 16:41:30 by bschaafs      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

static void		print_message(const std::string msg);

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

Fixed::Fixed(const Fixed &fixed)
{
	print_message("Copy constructor called");
	this->_value = fixed._value;
}

Fixed::~Fixed()
{
	print_message("Destructor called");
}


// #############################################################################
// 		MEMBER FUNCTIONS
// #############################################################################

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
// 		NON MEMBER OPERATORS
// #############################################################################

std::ostream&	operator<<(std::ostream& o, const Fixed& fixed)
{
	o << fixed.toFloat();
	return (o);
}

bool			operator<(Fixed const& fixed1, Fixed const& fixed2)
{
	return (fixed1.getRawBits() < fixed2.getRawBits());
}

bool			operator>(Fixed const& fixed1, Fixed const& fixed2)
{
	return (fixed1.getRawBits() > fixed2.getRawBits());
}

bool			operator<=(Fixed const& fixed1, Fixed const& fixed2)
{
	return (fixed1.getRawBits() <= fixed2.getRawBits());
}

bool			operator>=(Fixed const& fixed1, Fixed const& fixed2)
{
	return (fixed1.getRawBits() >= fixed2.getRawBits());
}

bool			operator==(Fixed const& fixed1, Fixed const& fixed2)
{
	return (fixed1.getRawBits() == fixed2.getRawBits());
}

bool			operator!=(Fixed const& fixed1, Fixed const& fixed2)
{
	return (fixed1.getRawBits() != fixed2.getRawBits());
}

float			operator+(Fixed const& fixed1, Fixed const& fixed2)
{
	int	rawBits = fixed1.getRawBits() + fixed2.getRawBits();
	return static_cast<float>(rawBits) / (1 << 8);
}

float			operator-(Fixed const& fixed1, Fixed const& fixed2)
{
	int	rawBits = fixed1.getRawBits() - fixed2.getRawBits();
	return static_cast<float>(rawBits) / (1 << 8);
}

float			operator*(Fixed const& fixed1, Fixed const& fixed2)
{
	return fixed1.toFloat() * fixed2.toFloat();
}

float			operator/(Fixed const& fixed1, Fixed const& fixed2)
{
	return fixed1.toFloat() / fixed2.toFloat();
}


// #############################################################################
// 		MEMBER OPERATORS
// #############################################################################

Fixed&	Fixed::operator=(const Fixed& original)
{
	print_message("Copy assignment operator called");
	if (this != &original)
		this->_value = original.getRawBits();
	return (*this);
}

Fixed			Fixed::operator++(int)
{
	Fixed	temp = *this;
	this->setRawBits(this->getRawBits() + 1);
	return temp;
}

Fixed			Fixed::operator--(int)
{
	Fixed	temp = *this;
	this->setRawBits(this->getRawBits() - 1);
	return temp;
}

Fixed			&Fixed::operator--()
{
	this->setRawBits(this->getRawBits() - 1);
	return *this;
}

Fixed			&Fixed::operator++()
{
	this->setRawBits(this->getRawBits() + 1);
	return *this;
}


// #############################################################################
// 		MIN/MAX
// #############################################################################

Fixed&	Fixed::min(Fixed& fixed1, Fixed& fixed2)
{
	if (fixed1.getRawBits() < fixed2.getRawBits())
		return fixed1;
	return fixed2;
}

const Fixed&	Fixed::min(const Fixed& fixed1, const Fixed& fixed2)
{
	if (fixed1.getRawBits() < fixed2.getRawBits())
		return fixed1;
	return fixed2;
}

Fixed&	Fixed::max(Fixed& fixed1, Fixed& fixed2)
{
	if (fixed1.getRawBits() > fixed2.getRawBits())
		return fixed1;
	return fixed2;
}

const Fixed&	Fixed::max(const Fixed& fixed1, const Fixed& fixed2)
{
	if (fixed1.getRawBits() > fixed2.getRawBits())
		return (fixed1);
	return fixed2;
}


// #############################################################################
// 		HELPER FUNCTIONS
// #############################################################################

static void	print_message(const std::string msg)
{
	if (LOG == 1)
		std::cout << msg << std::endl;
}

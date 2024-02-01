/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Point.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bschaafs <bschaafs@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/11 17:17:19 by bschaafs      #+#    #+#                 */
/*   Updated: 2024/01/11 18:03:00 by bschaafs      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// #############################################################################
// 		CON/DE STRUCTORS
// #############################################################################

Point::Point(void) : _x(0), _y(0)
{
}

Point::Point(const float x, const float y): _x(x), _y(y)
{
}

Point::Point(const Point& point): _x(point.getX()), _y(point.getY())
{
}

Point::~Point()
{
}


// #############################################################################
// 		MEMBER FUNCTIONS
// #############################################################################

Point&		Point::operator=(const Point& original)
{
	if (this != &original)
	{
		(Fixed) this->_x = original.getX();
		(Fixed) this->_y = original.getY();
	}
	return *this;
}

const Fixed&	Point::getX(void) const
{
	return (this->_x);
}

const Fixed&	Point::getY(void) const
{
	return (this->_y);
}

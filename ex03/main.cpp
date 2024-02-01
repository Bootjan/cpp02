/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bschaafs <bschaafs@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/11 17:31:41 by bschaafs      #+#    #+#                 */
/*   Updated: 2024/01/11 17:58:42 by bschaafs      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int	main()
{
	Point	a(0, 0);
	Point	b(0, 5);
	Point	c(5, 0);
	Point	point(0,0);

	if (bsp(a, b, c, point))
		std::cout << "Point is inside triangle" << std::endl;
	else
		std::cout << "Point is not inside triangle" << std::endl;
	return (0);
}

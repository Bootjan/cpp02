/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bsp.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: bschaafs <bschaafs@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/11 17:19:23 by bschaafs      #+#    #+#                 */
/*   Updated: 2024/01/11 18:01:42 by bschaafs      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static float	absf(float x)
{
	if (x < 0)
		return -x;
	return x;
}

static float	areaOfTriangle(Point const p1, Point const p2, Point const p3)
{
	return absf((p1.getX() * (p2.getY() - p3.getY()) + p2.getX() * (p3.getY() - p1.getY()) + p3.getX() * (p1.getY() - p2.getY())) / 2.0);
}

bool	bsp( Point const a, Point const b, Point const c, Point const point)
{
	float	area, area1, area2, area3;

	area = areaOfTriangle(a, b, c);
	area1 = areaOfTriangle(a, b, point);
	area2 = areaOfTriangle(a, c, point);
	area3 = areaOfTriangle(b, c, point);

	if (!area1 || !area2 || !area3)
		return false;
	return (area1 + area2 + area3) == area;
}

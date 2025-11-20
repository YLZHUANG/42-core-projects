/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:08:36 by yzhuang           #+#    #+#             */
/*   Updated: 2024/01/31 14:09:19 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point) {

	Point vab(Fixed(b.getX() - a.getX()), Fixed(b.getY() - a.getY()));
	Point vbc(Fixed(c.getX() - b.getX()), Fixed(c.getY() - b.getY()));
	Point vca(Fixed(a.getX() - c.getX()), Fixed(a.getY() - c.getY()));

	Fixed crossProductAB = vab.crossProduct(Point(point.getX() - a.getX(), point.getY() - a.getY()));
	Fixed crossProductBC = vbc.crossProduct(Point(point.getX() - b.getX(), point.getY() - b.getY()));
	Fixed crossProductCA = vca.crossProduct(Point(point.getX() - c.getX(), point.getY() - c.getY()));

	if (crossProductAB > 0 && crossProductBC > 0 && crossProductCA > 0) {
		return (true);
	}
	
	if (crossProductAB < 0 && crossProductBC < 0 && crossProductCA < 0) {
		return (true);
	}

	return (false);
}

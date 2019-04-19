/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 10:33:48 by sarobber          #+#    #+#             */
/*   Updated: 2019/04/19 15:10:22 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void echangerEntiers(int* x, int* y)
{
	int t = *x;
	*x = *y;
	*y = t;
}

void ligne(int x1, int y1, int x2, int y2, int coul, t_env *e)
{
	int d, dx, dy, aincr, bincr, xincr, yincr, x, y;

	if (abs(x2 - x1) < abs(y2 - y1))
	{
		if (y1 > y2) 
		{
			echangerEntiers(&x1, &x2);
			echangerEntiers(&y1, &y2);
		}
		xincr = x2 > x1 ? 1 : -1;
		dy = y2 - y1;
		dx = abs(x2 - x1);
		d = 2 * dx - dy;
		aincr = 2 * (dx - dy);
		bincr = 2 * dx;
		x = x1;
		y = y1;
		e->data[y * LENGTH + x] = coul;
		while (++y <= y2)
		{
			if (d >= 0)
			{
				x += xincr;
				d += aincr;
			}
			else
				d += bincr;
			e->data[y * LENGTH + x] = coul;
		}

	}
	else
	{
		if (x1 > x2)
		{
			echangerEntiers(&x1, &x2);
			echangerEntiers(&y1, &y2);
		}
		yincr = y2 > y1 ? 1 : -1;
		dx = x2 - x1;
		dy = abs(y2 - y1);
		d = 2 * dy - dx;
		aincr = 2 * (dy - dx);
		bincr = 2 * dy;
		x = x1;
		y = y1;
		e->data[y * LENGTH + x] = coul;
		while (++x <= x2)
		{
			if (d >= 0)
			{
				y += yincr;
				d += aincr;
			}
			else
				d += bincr;
			e->data[y * LENGTH + x] = coul;
		}
	}    
}

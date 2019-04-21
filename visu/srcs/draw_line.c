/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 10:33:48 by sarobber          #+#    #+#             */
/*   Updated: 2019/04/21 12:20:51 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

t_point		new_point(int x, int y)
{
	t_point	point;

	point.x = x;
	point.y = y;
	return (point);
}

void echangerEntiers(int* x, int* y)
{
	int t = *x;
	*x = *y;
	*y = t;
}

void 	cas1(t_point p1, t_point p2, int coul, t_env *e)
{
	t_ligne	ligne;
	int 	x;
	int		y;

	if (p1.y > p2.y) 
	{
		echangerEntiers(&p1.x, &p2.x);
		echangerEntiers(&p1.y, &p2.y);
	}
	ligne.xincr = p2.x > p1.x ? 1 : -1;
	ligne.dy = p2.y - p1.y;
	ligne.dx = abs(p2.x - p1.x);
	ligne.d = 2 * ligne.dx - ligne.dy;
	ligne.aincr = 2 * (ligne.dx - ligne.dy);
	ligne.bincr = 2 * ligne.dx;
	x = p1.x;
	y = p1.y;
	e->data[y * LENGTH + x] = coul;
	while (++y <= p2.y)
	{
		if (ligne.d >= 0)
		{
			x += ligne.xincr;
			ligne.d += ligne.aincr;
		}
		else
			ligne.d += ligne.bincr;
		e->data[y * LENGTH + x] = coul;
	}
}

void 	cas2(t_point p1, t_point p2, int coul, t_env *e)
{
	t_ligne	ligne;
	int 	x;
	int		y;
	if (p1.x > p2.x)
	{
		echangerEntiers(&p1.x, &p2.x);
		echangerEntiers(&p1.y, &p2.y);
	}
	ligne.yincr = p2.y > p1.y ? 1 : -1;
	ligne.dx = p2.x - p1.x;
	ligne.dy = abs(p2.y - p1.y);
	ligne.d = 2 * ligne.dy - ligne.dx;
	ligne.aincr = 2 * (ligne.dy - ligne.dx);
	ligne.bincr = 2 * ligne.dy;
	x = p1.x;
	y = p1.y;
	e->data[y * LENGTH + x] = coul;
	while (++x <= p2.x)
	{
		if (ligne.d >= 0)
		{
			y += ligne.yincr;
			ligne.d += ligne.aincr;
		}
		else
			ligne.d += ligne.bincr;
		e->data[y * LENGTH + x] = coul;
	}
}

void ligne(t_point p1, t_point p2, int coul, t_env *e)
{
	if (abs(p2.x - p1.x) < abs(p2.y - p1.y))
		cas1(p1, p2, coul, e);
	else
		cas2(p1, p2, coul, e);
}
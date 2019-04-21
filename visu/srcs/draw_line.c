/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 16:08:40 by sarobber          #+#    #+#             */
/*   Updated: 2019/04/21 16:14:00 by sarobber         ###   ########.fr       */
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

void		swap(int *x, int *y)
{
	int t;

	t = *x;
	*x = *y;
	*y = t;
}

void		cas1(t_point p1, t_point p2, int coul, t_env *e)
{
	t_line	line;
	int		x;
	int		y;

	line.xincr = p2.x > p1.x ? 1 : -1;
	line.dy = p2.y - p1.y;
	line.dx = abs(p2.x - p1.x);
	line.d = 2 * line.dx - line.dy;
	line.aincr = 2 * (line.dx - line.dy);
	line.bincr = 2 * line.dx;
	x = p1.x;
	y = p1.y;
	e->data[y * LENGTH + x] = coul;
	while (++y <= p2.y)
	{
		if (line.d >= 0)
		{
			x += line.xincr;
			line.d += line.aincr;
		}
		else
			line.d += line.bincr;
		e->data[y * LENGTH + x] = coul;
	}
}

void		cas2(t_point p1, t_point p2, int coul, t_env *e)
{
	t_line	line;
	int		x;
	int		y;

	line.yincr = p2.y > p1.y ? 1 : -1;
	line.dx = p2.x - p1.x;
	line.dy = abs(p2.y - p1.y);
	line.d = 2 * line.dy - line.dx;
	line.aincr = 2 * (line.dy - line.dx);
	line.bincr = 2 * line.dy;
	x = p1.x;
	y = p1.y;
	e->data[y * LENGTH + x] = coul;
	while (++x <= p2.x)
	{
		if (line.d >= 0)
		{
			y += line.yincr;
			line.d += line.aincr;
		}
		else
			line.d += line.bincr;
		e->data[y * LENGTH + x] = coul;
	}
}

void		draw_line(t_point p1, t_point p2, int coul, t_env *e)
{
	if (abs(p2.x - p1.x) < abs(p2.y - p1.y))
	{
		if (p1.y > p2.y)
		{
			swap(&p1.x, &p2.x);
			swap(&p1.y, &p2.y);
		}
		cas1(p1, p2, coul, e);
	}
	else
	{
		if (p1.x > p2.x)
		{
			swap(&p1.x, &p2.x);
			swap(&p1.y, &p2.y);
		}
		cas2(p1, p2, coul, e);
	}
}

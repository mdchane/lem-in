/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 12:39:11 by sarobber          #+#    #+#             */
/*   Updated: 2019/03/20 16:08:29 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"
#include <math.h>

void		draw_square(int cx, int cy, int rayon, int coul, t_env *e)
{
	int x;
	int y;

	x = cx - rayon;
	y = cy - rayon;
	while (x < cx + rayon)
	{
		y = cy - rayon;
		while (y < cy + rayon)
		{
			if (y == cy - rayon || x == cx - rayon || x == cx + rayon - 1)
				e->data[(int)(y * LENGTH + x)] = 0XFFFFFF;
			else
				e->data[(int)(y * LENGTH + x)] = coul;
			y++;
		}
		e->data[(int)(y * LENGTH + x)] = 0XFFFFFF;
		x++;
	}
}

void		draw_room(t_env *e)
{
	t_room *beg;

	beg = e->room;
	while (e->room)
	{
		draw_square(e->room->x * e->scale.x + 100, e->room->y * e->scale.y + 100, 20, e->room->col, e);
		e->room = e->room->next;
	}
	e->room = beg;
}

void echangerEntiers(int* x, int* y)
{
  int t = *x;
  *x = *y;
  *y = t;
}

void ligne(int x1, int y1, int x2, int y2, int coul, t_env *e)
{
  int d, dx, dy, aincr, bincr, xincr, yincr, x, y;
 
  if (abs(x2 - x1) < abs(y2 - y1)) {
 
    if (y1 > y2) {
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
	e->data[(y - 1) * LENGTH + x] = coul;
	e->data[(y - 1) * LENGTH + (x + 1)] = coul;
	e->data[(y - 1)* LENGTH + (x - 1)] = coul;
	e->data[y * LENGTH + (x + 1)] = coul;
	e->data[y * LENGTH + (x - 1)] = coul;
	e->data[(y + 1) * LENGTH + x] = coul;
	e->data[(y + 1) * LENGTH + (x + 1)] = coul;
	e->data[(y + 1) * LENGTH + (x - 1)] = coul;
    for (y = y1+1; y <= y2; ++y) {
      if (d >= 0) {
	x += xincr;
	d += aincr;
      } else
	d += bincr;
	e->data[y * LENGTH + x] = coul;
	e->data[(y - 1) * LENGTH + x] = coul;
	e->data[(y - 1) * LENGTH + (x + 1)] = coul;
	e->data[(y - 1)* LENGTH + (x - 1)] = coul;
	e->data[y * LENGTH + (x + 1)] = coul;
	e->data[y * LENGTH + (x - 1)] = coul;
	e->data[(y + 1) * LENGTH + x] = coul;
	e->data[(y + 1) * LENGTH + (x + 1)] = coul;
	e->data[(y + 1) * LENGTH + (x - 1)] = coul;
    }
 
  } else {
    
    if (x1 > x2) {
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
	e->data[(y - 1) * LENGTH + x] = coul;
	e->data[(y - 1) * LENGTH + (x + 1)] = coul;
	e->data[(y - 1)* LENGTH + (x - 1)] = coul;
	e->data[y * LENGTH + (x + 1)] = coul;
	e->data[y * LENGTH + (x - 1)] = coul;
	e->data[(y + 1) * LENGTH + x] = coul;
	e->data[(y + 1) * LENGTH + (x + 1)] = coul;
	e->data[(y + 1) * LENGTH + (x - 1)] = coul;
    for (x = x1+1; x <= x2; ++x) {
      if (d >= 0) {
	y += yincr;
	d += aincr;
      } else
	d += bincr;
	e->data[y * LENGTH + x] = coul;
	e->data[(y - 1) * LENGTH + x] = coul;
	e->data[(y - 1) * LENGTH + (x + 1)] = coul;
	e->data[(y - 1)* LENGTH + (x - 1)] = coul;
	e->data[y * LENGTH + (x + 1)] = coul;
	e->data[y * LENGTH + (x - 1)] = coul;
	e->data[(y + 1) * LENGTH + x] = coul;
	e->data[(y + 1) * LENGTH + (x + 1)] = coul;
	e->data[(y + 1) * LENGTH + (x - 1)] = coul;
    }
  }    
}
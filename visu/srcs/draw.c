/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 12:39:11 by sarobber          #+#    #+#             */
/*   Updated: 2019/03/19 17:25:13 by sarobber         ###   ########.fr       */
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
 
    mlx_pixel_put(e->mlx_ptr, e->win_ptr, x, y, coul);
 
    for (y = y1+1; y <= y2; ++y) {
      if (d >= 0) {
	x += xincr;
	d += aincr;
      } else
	d += bincr;
      mlx_pixel_put(e->mlx_ptr, e->win_ptr,x, y, coul);
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
 
    mlx_pixel_put(e->mlx_ptr, e->win_ptr,x, y, coul);
 
    for (x = x1+1; x <= x2; ++x) {
      if (d >= 0) {
	y += yincr;
	d += aincr;
      } else
	d += bincr;
 
      mlx_pixel_put(e->mlx_ptr, e->win_ptr,x, y, coul);
    }
  }    
}

void		draw_cercle(int cx, int cy, int rayon, int coul, t_env *e)
{
	int d, y, x;
 
	d = 3 - (2 * rayon);
	x = 0;
	y = rayon;
	while (y >= x)
	{
		mlx_pixel_put(e->mlx_ptr, e->win_ptr, cx + x, cy + y, coul);
		mlx_pixel_put(e->mlx_ptr, e->win_ptr, cx + x, cy + y, coul);
		mlx_pixel_put(e->mlx_ptr, e->win_ptr, cx - x, cy + y, coul);
		mlx_pixel_put(e->mlx_ptr, e->win_ptr, cx - x, cy + y, coul);
		mlx_pixel_put(e->mlx_ptr, e->win_ptr, cx + x, cy - y, coul);
		mlx_pixel_put(e->mlx_ptr, e->win_ptr, cx + x, cy - y, coul);
		mlx_pixel_put(e->mlx_ptr, e->win_ptr, cx - x, cy - y, coul);
		mlx_pixel_put(e->mlx_ptr, e->win_ptr, cx - x, cy - y, coul);
    if (d < 0)
      d = d + (4 * x) + 6;
    else {
      d = d + 4 * (x - y) + 10;
      y--;
    }
    x++;
  }
  mlx_string_put(e->mlx_ptr, e->win_ptr, cx - 5, cy - 5, 0XFFFFFF, e->room->name);
}

void		draw_room(t_env *e)
{
	t_room *beg;

	beg = e->room;
	while (e->room)
	{
		draw_cercle(e->room->x * e->scale.x + 100, e->room->y * e->scale.y + 100, 20, 0XFFFF00, e);
		e->room = e->room->next;
	}
	e->room = beg;
}
// void	new_pos(t_point *pos, t_point point1, t_point step, int index)
// {
//         pos->x = point1.x + index * step.x;
//         pos->y = point1.y + index * step.y;
// }

// void			get_step(t_point p1, t_point p2, t_point *step)
// {
// 	step->x = p2.x - p1.x;
// 	step->y = p2.y - p1.y;
// }

// int				get_path(t_point *step, t_point tmp)
// {
// 	int			k;

// 	if (tmp.x > tmp.y)
// 	{
// 		k = ABS(step->x);
// 		step->y /= ABS(step->x);
// 		step->x /= ABS(step->x);
// 	}
// 	else
// 	{
// 		k = ABS(step->y);
// 		step->x /= ABS(step->y);
// 		step->y /= ABS(step->y);
// 	}
// 	return (k);
// }

// void                    drawline(t_point point1, t_point point2, t_env *e)
// {
//         t_point      tmp;
//         t_point      step;
//         t_point      pos;
//         int                     k;
//         int                     index;

//         index = 0;
//         get_step(point1, point2, &step);
//         tmp = create_point(ABS(step.x), ABS(step.y));
//         k = get_path(&step, tmp);
//         while (index < k)
//         {
//             new_pos(&pos, point1, step, index);
//             if ((pos.x >= 0 && pos.x < WIDTH) && (pos.y >= 0 && pos.y < LENGTH))
//                  mlx_pixel_put(e->mlx_ptr, e->win_ptr, pos.x, pos.y, 0XFFFFFF);
//             index++;
//         }
// }
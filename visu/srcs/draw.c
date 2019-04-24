/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 12:39:11 by sarobber          #+#    #+#             */
/*   Updated: 2019/04/24 11:33:49 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"
#include <math.h>

void		draw_square(t_point point, int rayon, int coul, t_env *e)
{
	int x;
	int y;

	x = point.x - rayon;
	y = point.y - rayon;
	while (x < point.x + rayon)
	{
		y = point.y - rayon;
		while (y < point.y + rayon)
		{
			if (y == point.y - rayon
				|| x == point.x - rayon || x == point.x + rayon - 1)
				e->data[(int)(y * LENGTH + x)] = WHITE;
			else
				e->data[(int)(y * LENGTH + x)] = coul;
			y++;
		}
		e->data[(int)(y * LENGTH + x)] = WHITE;
		x++;
	}
}

void		draw_room(t_env *e)
{
	t_room *beg;

	beg = e->room;
	while (e->room)
	{
		draw_square(new_point(e->room->x, e->room->y), 20, e->room->col, e);
		e->room = e->room->next;
	}
	e->room = beg;
}

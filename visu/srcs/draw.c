/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 12:39:11 by sarobber          #+#    #+#             */
/*   Updated: 2019/04/21 12:56:32 by sarobber         ###   ########.fr       */
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
		draw_square(e->room->x, e->room->y, 20, e->room->col, e);
		e->room = e->room->next;
	}
	e->room = beg;
}
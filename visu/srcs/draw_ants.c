/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 17:33:37 by sarobber          #+#    #+#             */
/*   Updated: 2019/04/21 13:34:35 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "visu.h"

void	draw_red(t_env *e)
{
	int x;
	int y;
	int i;

	i = 0;
	while (i < e->nb_ants)
	{
		if (e->ants[i].parent)
		{
			x = (e->ants[i].parent->x + e->ants[i].room->x) / 2;
			y = (e->ants[i].parent->y + e->ants[i].room->y) / 2;
			draw_square(x, y, 5, RED, e);
		}
		i++;
	}
}

void	del_ants(t_env *e)
{
	t_room *beg;

	beg = e->room;
	while (e->room)
	{
		if (e->room->ants == 0 && (e->room != e->start) && (e->room != e->end))
			draw_square(e->room->x, e->room->y, 20,  N_BLUE, e);
		e->room = e->room->next;
	}
	e->room = beg;
}

void	draw_ants(t_env *e, char *line)
{
	char **step;
	char **split;

	t_room	*a;
	t_room	*b;
	int i;
	
	i = 0;
	step = ft_strsplit(line, ' ');
	while (step[i])
	{
		split = ft_strsplit(step[i], '-');
		a = e->ants[ft_atoi(split[0] + 1) - 1].room;
		b = room_search(e->room, split[1]);
		e->ants[ft_atoi(split[0] + 1) - 1].room = b;
		e->ants[ft_atoi(split[0] + 1) - 1].parent = a;
		a->ants--;
		b->ants++;
		draw_square((a->x + b->x) / 2, (a->y + b->y) / 2, 5, GREEN, e);
		draw_square(b->x, b->y, 20, S_BLUE, e);
		del_ants(e);
		i++;
		free_tab(&split);
	}
	free_tab(&step);
	if (e->end->ants == e->nb_ants)
		draw_square(e->end->x, e->end->y, 20, RED, e);
}
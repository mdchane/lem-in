/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 15:08:05 by sarobber          #+#    #+#             */
/*   Updated: 2019/04/19 15:19:02 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void	get_scale(t_env *e)
{
	int x;
	int y;
	t_room *beg;

	beg = e->room;
	x = beg->x;
	y = beg->y;
	while (beg)
	{
		if (beg->x > e->xmax)
			e->xmax = beg->x;
		if (beg->y > e->ymax)
			e->ymax = beg->y;
		beg = beg->next;
	}
	e->scale.x = (700 / e->xmax);
	e->scale.y = (700 / e->ymax);
}


void	count_ants(t_env *e)
{
	int i;

	i = 0;
	while (i < e->nb_ants)
	{
		if (e->ants[i].room == e->end)
			i++;
	}
}

void	count_end_ants(t_env *e)
{
	int i;

	i = 0;
	while (i < e->nb_ants)
	{
		if (e->ants[i].room == e->end)
			e->end->ants++;
		i++;
	}
}

void	get_coord(t_env *e)
{
	t_room *beg;

	beg = e->room;
	e->start->ants = e->nb_ants;
	while (e->room)
	{
		e->room->x = (int)(e->room->x * e->scale.x + 100);
		e->room->y = (int)(e->room->y * e->scale.y + 100);
		e->room = e->room->next;
	}
	e->room = beg;
}
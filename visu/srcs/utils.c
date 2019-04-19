/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 15:08:05 by sarobber          #+#    #+#             */
/*   Updated: 2019/04/19 16:09:25 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void	print_menu(t_env *e)
{
	char *end_ants;

	end_ants = ft_itoa(e->end->ants);
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->img_ptr, 0, 0);
	mlx_string_put(e->mlx_ptr, e->win_ptr, e->end->x, e->end->y, 0xFFFFFF, end_ants);
	mlx_string_put(e->mlx_ptr, e->win_ptr, 20, 20, 0xFFFFFF, "ESPACE : Prochaie Etape");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 20, 50, 0xFFFFFF, "A : ON/OFF Automatique");
	if (end_ants)
		free(end_ants);
}

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
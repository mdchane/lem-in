/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 17:33:37 by sarobber          #+#    #+#             */
/*   Updated: 2019/04/19 14:12:31 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "visu.h"
#include <math.h>

void	del_ants(t_env *e)
{
	t_room *beg;

	beg = e->room;
	while (e->room)
	{
		if (e->room->ants == 0)
			draw_square(e->room->x, e->room->y, 20,  0X000080, e);
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
		draw_square((a->x + b->x) / 2, (a->y + b->y) / 2, 5, 0X00FF00, e);
		draw_square(b->x, b->y, 20, 0X00BFFF, e);
		mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->img_ptr, 0, 0);
		del_ants(e);

		if (e->ants[ft_atoi(split[0] + 1) - 1].room == e->end)
			e->end->ants++;
		i++;
	}
	if (e->end->ants == e->nb_ants)
		e->step = -1;
}
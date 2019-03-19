/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_v.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 11:49:05 by sarobber          #+#    #+#             */
/*   Updated: 2019/03/19 17:24:56 by sarobber         ###   ########.fr       */
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

void	error(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(EXIT_FAILURE);
}

int		ft_key_hook(int keycode, t_env *e)
{
	char *line;

	if (keycode == 53)
	{
		mlx_destroy_window(e->mlx_ptr, e->win_ptr);
		exit(EXIT_FAILURE);
	}
	if ((keycode == 49) && (e->map == 0))
	{
		e->map = 1;
		line = parse_room(e);
		get_scale(e);
		draw_room(e);
		parse_path(line, e);
	}
	return (1);
}

int		main(void)
{
	t_env e;

	e.nb_ants = -1;
	e.map = 0;
	e.xmax = 0;
	e.ymax = 0;
	e.mlx_ptr = mlx_init();
	e.win_ptr = mlx_new_window(e.mlx_ptr, WIDTH, LENGTH, "Visualisateur Lem-in");
	mlx_hook(e.win_ptr, 2, 0, ft_key_hook, &e);
	mlx_loop(e.mlx_ptr);
	return (0);
}
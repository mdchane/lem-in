/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_v.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 11:49:05 by sarobber          #+#    #+#             */
/*   Updated: 2019/04/24 11:40:17 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int		error(void)
{
	exit(EXIT_FAILURE);
}

void	init(t_env *e)
{
	int		bpp;
	int		s_l;
	int		endian;

	e->nb_ants = -1;
	e->step = 0;
	e->fin = 0;
	e->aff_name = 0;
	e->autom = 0;
	e->xmax = 0;
	e->count = -1;
	e->ymax = 0;
	e->img_ptr = mlx_new_image(e->mlx_ptr, WIDTH, LENGTH);
	e->data = (int *)mlx_get_data_addr(e->img_ptr, &(bpp), &(s_l), &(endian));
	e->mlx_ptr = mlx_init();
	e->win_ptr =
	mlx_new_window(e->mlx_ptr, WIDTH, LENGTH, "Visualisateur Lem-in");
}

int		ft_key_hook(int keycode, t_env *e)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(e->mlx_ptr, e->win_ptr);
		exit(EXIT_SUCCESS);
	}
	if (keycode == KEY_ESP && !e->fin)
	{
		draw_red(e);
		if (e->path[e->step])
			draw_ants(e, e->path[e->step]);
		if (e->end->ants >= e->nb_ants)
			e->fin = 1;
		e->end->ants = 0;
		count_end_ants(e);
		e->count = 30;
		e->step++;
	}
	if (keycode == KEY_A)
		e->autom = (e->autom == 1) ? 0 : 1;
	if (keycode == 1)
		e->aff_name = (e->aff_name == 1) ? 0 : 1;
	return (1);
}

int		loop_hook(t_env *e)
{
	if (e->autom == 1 && !e->fin)
	{
		draw_red(e);
		if (e->path[e->step])
			draw_ants(e, e->path[e->step]);
		if (e->end->ants >= e->nb_ants)
			e->fin = 1;
		e->end->ants = 0;
		count_end_ants(e);
		e->step++;
		usleep(500000);
	}
	else if (e->fin)
		draw_red(e);
	if (e->count > -1)
		e->count--;
	if (e->count == 0)
		draw_red(e);
	if (!e->path[e->step])
		e->fin = 1;
	print_menu(e);
	return (1);
}

int		main(void)
{
	t_env	e;

	init(&e);
	parser(&e);
	e.ants = create_ants(&e);
	mlx_hook(e.win_ptr, 2, 0, ft_key_hook, &e);
	mlx_hook(e.win_ptr, 17, 0, error, &e);
	mlx_loop_hook(e.mlx_ptr, loop_hook, &e);
	mlx_loop(e.mlx_ptr);
	return (0);
}

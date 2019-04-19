/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_v.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 11:49:05 by sarobber          #+#    #+#             */
/*   Updated: 2019/04/19 15:40:24 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void	error(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(EXIT_FAILURE);
}

void	init(t_env *e)
{
	int		bpp;
    int		s_l;
    int		endian;

	e->nb_ants = -1;
	e->step = 0;
	e->autom = 0;	
	e->xmax = 0;
	e->test = -1;
	e->ymax = 0;
	e->img_ptr = mlx_new_image(e->mlx_ptr, WIDTH, LENGTH);
	e->data = (int *)mlx_get_data_addr(e->img_ptr, &(bpp), &(s_l), &(endian));
	e->mlx_ptr = mlx_init();
	e->win_ptr = mlx_new_window(e->mlx_ptr, WIDTH, LENGTH, "Visualisateur Lem-in");
}

int		ft_key_hook(int keycode, t_env *e)
{
	int i;
	int fin;

	i = 0;
	fin = 0;
	if (keycode == 53)
	{
		mlx_destroy_window(e->mlx_ptr, e->win_ptr);
		exit(EXIT_FAILURE);
	}
	if (keycode == 49 && e->autom == 0)
	{
		draw_red(e);
		if (e->path[e->step])
			draw_ants(e, e->path[e->step]);
		if (e->end->ants >= e->nb_ants)
			return (0);
		e->end->ants = 0;
		count_end_ants(e);
		e->test = 30;
		e->step++;
	}
	if (keycode == 0)
		e->autom = 1;
	return (1);
}

int		loop_hook(t_env *e)
{
	char *end_ants;

	if (e->autom == 1)
	{
		draw_red(e);
		if (e->path[e->step])
			draw_ants(e, e->path[e->step]);
		if (e->end->ants >= e->nb_ants)
			e->autom = -1;
		e->end->ants = 0;
		count_end_ants(e);
		e->step++;
		usleep(500000);
	}
	if (e->test > -1)
		e->test--;
	if (e->test == 0)
		draw_red(e);
	end_ants = ft_itoa(e->end->ants);
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->img_ptr, 0, 0);
	mlx_string_put(e->mlx_ptr, e->win_ptr, e->end->x, e->end->y, 0xFFFFFF, end_ants);
	mlx_string_put(e->mlx_ptr, e->win_ptr, 20, 20, 0xFFFFFF, "ESPACE : Prochaie Etape");
	return (1);
}

int		main(void)
{
	t_env	e;

	init(&e);
	parser(&e);
	e.ants = create_ants(&e);
	mlx_hook(e.win_ptr, 2, 0, ft_key_hook, &e);
	mlx_loop_hook(e.mlx_ptr, loop_hook, &e);
	mlx_loop(e.mlx_ptr);
	return (0);
}

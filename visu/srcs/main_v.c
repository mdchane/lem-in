/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_v.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 11:49:05 by sarobber          #+#    #+#             */
/*   Updated: 2019/04/19 14:11:48 by sarobber         ###   ########.fr       */
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

void	draw_red(t_env *e)
{
	int x;
	int y;
	int i;

	i = 0;
	write (1, "0", 1);
	while (i < e->nb_ants)
	{
		if (e->ants[i].parent)
		{
			x = (e->ants[i].parent->x + e->ants[i].room->x) / 2;
			y = (e->ants[i].parent->y + e->ants[i].room->y) / 2;
			draw_square(x, y, 5, 0XFF0000, e);
		}
		i++;
	}
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
	if (keycode == 49 && e->step != -1)
	{
		if (e->path[e->step])
			draw_ants(e, e->path[e->step]);
		else if (e->end->ants >= e->nb_ants)
			return (0);
		e->test = 30;
		e->step++;
	}
	return (1);
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

int		loop_hook(t_env *e)
{
	printf("%d\n", e->test);
	if (e->test > -1)
		e->test--;
	if (e->test == 0)
		draw_red(e);
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->img_ptr, 0, 0);
	return (1);
}

int		main(void)
{
	t_env	e;
    int		bpp;
    int		s_l;
    int		endian;
	char 	*line;

	e.nb_ants = -1;
	e.step = 0;	
	e.xmax = 0;
	e.test = -1;
	e.ymax = 0;
	e.img_ptr = mlx_new_image(e.mlx_ptr, WIDTH, LENGTH);
	e.data = (int *)mlx_get_data_addr(e.img_ptr, &(bpp), &(s_l), &(endian));
	e.mlx_ptr = mlx_init();
	e.win_ptr = mlx_new_window(e.mlx_ptr, WIDTH, LENGTH, "Visualisateur Lem-in");
	line = parse_room(&e);
	get_scale(&e);
	get_coord(&e);
	parse_neigh(line, &e);
	draw_room(&e);
	mlx_put_image_to_window(e.mlx_ptr, e.win_ptr, e.img_ptr, 0, 0);
	create_path(&e);
	e.ants = create_ants(&e);
	mlx_hook(e.win_ptr, 2, 0, ft_key_hook, &e);
	mlx_loop_hook(e.mlx_ptr, loop_hook, &e);
	mlx_loop(e.mlx_ptr);
	return (0);
}

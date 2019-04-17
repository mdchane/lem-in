/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw_ants.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sacha <sacha@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/17 17:33:37 by sarobber     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/17 23:49:16 by sacha       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "visu.h"
#include <math.h>

void	print_big_point(int x, int y, int coul, t_env *e)
{
	mlx_pixel_put(e->mlx_ptr, e->win_ptr, x, y, coul);
	mlx_pixel_put(e->mlx_ptr, e->win_ptr, x + 1, y + 1, coul);
	mlx_pixel_put(e->mlx_ptr, e->win_ptr, x + 1, y - 1, coul);
	mlx_pixel_put(e->mlx_ptr, e->win_ptr, x + 1, y, coul);
	mlx_pixel_put(e->mlx_ptr, e->win_ptr, x - 1, y + 1, coul);
	mlx_pixel_put(e->mlx_ptr, e->win_ptr, x - 1, y - 1, coul);
	mlx_pixel_put(e->mlx_ptr, e->win_ptr, x - 1, y, coul);
	mlx_pixel_put(e->mlx_ptr, e->win_ptr, x, y + 1, coul);
	mlx_pixel_put(e->mlx_ptr, e->win_ptr, x, y - 1, coul);
}
void	draw_path(t_room	*s, t_room	*f, t_env *e)
{
	int a;
	int b;
	t_point coord;
	t_point new_coord;
	int delta;
	
	coord.x = s->x;
	coord.y = s->y;
	a = ((s->y - f->y)/(s->x - f->x));
	b = coord.y - (coord.x * a);
	if (s->x > f->x)
		delta = -1;
	else
		delta = 1;
	while (coord.x != f->x)
	{
		print_big_point(coord.x, coord.y, 0X000000, e);
		new_coord.x = coord.x + delta;
		new_coord.y = (a * new_coord.x) + b;
		print_big_point(new_coord.x, new_coord.y, 0X000000, e);
		print_big_point(coord.x, coord.y, 0XFFFFFF, e);
		coord = new_coord;
	}
}

void	draw_ants(t_env *e, char *line)
{
	char **step;
	char **split;
	int i;
	t_room	*a;
	t_room	*b;

	i = 0;
	step = ft_strsplit(line, ' ');
	while (step[i])
	{
		split = ft_strsplit(step[i], '-');
		a = e->ants[ft_atoi(split[0] + 1) - 1].room;
		b = room_search(e->room, split[1]);
		e->ants[ft_atoi(split[0] + 1) - 1].room = b;
		// draw_path(a, b, e);
		i++;
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_v.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 11:52:48 by sarobber          #+#    #+#             */
/*   Updated: 2019/04/23 17:42:55 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void		find_room(char **split, t_env *e)
{
	t_room	*room_a;
	t_room	*room_b;
	int		midx;
	int		midy;

	room_a = room_search(e->room, split[0]);
	room_b = room_search(e->room, split[1]);
	midx = (room_a->x + room_b->x) / 2;
	midy = (room_a->y + room_b->y) / 2;
	draw_line(new_point(room_a->x, room_a->y),
		new_point(room_b->x, room_b->y), WHITE, e);
	draw_square(new_point(midx, midy), 5, RED, e);
	free_tab(&split);
}

char		*parse_neigh(char *line, t_env *e)
{
	if (is_neigh(line))
		find_room(ft_strsplit(line, '-'), e);
	ft_strdel(&line);
	while (get_next_line(0, &line) > 0)
	{
		if (is_neigh(line))
			find_room(ft_strsplit(line, '-'), e);
		else if (line[0] != '#')
			break ;
		ft_strdel(&line);
	}
	return (line);
}

void		parse_ants(t_env *e, char *line)
{
	if (is_nbr(line))
		e->nb_ants = ft_atoi(line);
	else
		error();
}

char		*parse_room(t_env *e, int type)
{
	char	*line;
	char	**split;

	while (get_next_line(0, &line) > 0)
	{
		split = ft_strsplit(line, ' ');
		type = find_type(line, type);
		if (e->nb_ants == -1)
			parse_ants(e, line);
		else if (type == -1 && is_room(split))
			room_push_front(&e->room, room_new(split[0],
				ft_atoi(split[1]), ft_atoi(split[2]), N_BLUE));
		else if (type == START && is_room(split))
			start_room(e, split, &type);
		else if (type == END && is_room(split))
			end_room(e, split, &type);
		else if (is_neigh(line))
			return (push_start(e, &split, line));
		else if (line[0] != '#')
			error();
		free(line);
		free_tab(&split);
	}
	error();
	return (NULL);
}

void		parser(t_env *e)
{
	char	*line;
	int		type;

	type = -1;
	e->room = NULL;
	line = parse_room(e, type);
	if (!e->room || !e->start || !e->end)
		error();
	get_scale(e);
	get_coord(e);
	line = parse_neigh(line, e);
	draw_room(e);
	create_path(e, line);
	ft_strdel(&line);
}

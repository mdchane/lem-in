/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_v.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 11:52:48 by sarobber          #+#    #+#             */
/*   Updated: 2019/04/21 15:16:32 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int		find_type(char *line, int type)
{
	if (ft_strcmp(line, "##start") == 0)
		return (START);
	else if (ft_strcmp(line, "##end") == 0)
		return (END);
	else
		return (type);
}

void		find_room(char **split, t_env *e)
{
	t_room	*room_a;
	t_room	*room_b;
	int 	midx;
	int 	midy;

	room_a = room_search(e->room, split[0]);
	room_b = room_search(e->room, split[1]);
	midx = (room_a->x + room_b->x) / 2;
	midy = (room_a->y + room_b->y) / 2;
	draw_line(new_point(room_a->x, room_a->y), new_point(room_b->x, room_b->y), WHITE, e);
	draw_square(midx, midy, 5, RED, e);
	free_tab(&split);
}

char	*parse_neigh(char *line, t_env *e)
{
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

char	*parse_room(t_env *e)
{
	char	*line;
	int		type;
	char	**split;

	e->room = NULL;
	type = -1;
	while (get_next_line(0, &line) > 0)
	{
		split = ft_strsplit(line, ' ');
		type = find_type(line, type);
		if (e->nb_ants == -1)
			e->nb_ants = ft_atoi(line);
		else if (type == -1 && is_room(split))
			room_push_front(&e->room, room_new(split[0], ft_atoi(split[1]), ft_atoi(split[2]), N_BLUE));
		else if (type == START && is_room(split))
		{
			e->start = room_new(split[0], ft_atoi(split[1]), ft_atoi(split[2]), GREEN);
			type = -1;
		}
		else if (type == END && is_room(split))
		{
			e->end = room_new(split[0], ft_atoi(split[1]), ft_atoi(split[2]), RED);
			room_push_back(&e->room, e->end);
			type = -1;
		}
		else if (is_neigh(line))
		{
			room_push_front(&e->room, e->start);
			free_tab(&split);
			return (line);
		}
		free(line);
		free_tab(&split);
	}
	if (!e->room)
		error();
	if (line)
		ft_strdel(&line);
	return (NULL);
}

void	parser(t_env *e)
{
	char *line;

	line = parse_room(e);
	get_scale(e);
	get_coord(e);
	line = parse_neigh(line, e);
	draw_room(e);
	create_path(e, line);
	while (1);
}

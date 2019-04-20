/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_v.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 11:52:48 by sarobber          #+#    #+#             */
/*   Updated: 2019/04/20 16:27:27 by sarobber         ###   ########.fr       */
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
	ligne(room_a->x, room_a->y, room_b->x, room_b->y, 0XFFFFFF, e);
	draw_square(midx, midy, 5, 0XFF0000, e);
}

char	*parse_neigh(char *line, t_env *e)
{
	find_room(ft_strsplit(line, '-'), e);
	while (get_next_line(0, &line) > 0)
	{
		if (is_neigh(line))
			find_room(ft_strsplit(line, '-'), e);
		else if (line[0] != '#')
			break ;
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
		if (e->nb_ants == -1)
			e->nb_ants = ft_atoi(line);
		type = find_type(line, type);
		split = ft_strsplit(line, ' ');
		if (type == -1 && is_room(split))
			room_push_front(&e->room, room_new(split[0], ft_atoi(split[1]), ft_atoi(split[2]), 0X000080));
		else if (type == START && is_room(split))
		{
			e->start = room_new(split[0], ft_atoi(split[1]), ft_atoi(split[2]), 0X00FF00);
			type = -1;
		}
		else if (type == END && is_room(split))
		{
			e->end = room_new(split[0], ft_atoi(split[1]), ft_atoi(split[2]), 0XFF0000);
			room_push_back(&e->room, e->end);
			type = -1;
		}
		else if (is_neigh(line))
		{
			room_push_front(&e->room, e->start);
			free_tab(split);
			return (line);
		}
		free_tab(split);
		free(line);
	}
	if (!e->room)
		error("ERROR\n");
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
}
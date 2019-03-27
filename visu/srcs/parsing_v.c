/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_v.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 11:52:48 by sarobber          #+#    #+#             */
/*   Updated: 2019/03/27 15:32:25 by mdchane          ###   ########.fr       */
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
	room_a = room_search(e->room, split[0]);
	room_b = room_search(e->room, split[1]);
	ligne(room_a->x * e->scale.x + 100, room_a->y * e->scale.y + 100, room_b->x * e->scale.x + 100, room_b->y * e->scale.y + 100, 0XFFFFFF, e);
//	drawline(create_point(room_a->x e->scale, room_a->y e->scale) , create_point(room_b->x e->scale, room_b->y e->scale), e);
}

void	parse_neigh(char *line, t_env *e)
{
	find_room(ft_strsplit(line, '-'), e);
	while (get_next_line(0, &line) > 0)
	{
		if (is_neigh(line))
			find_room(ft_strsplit(line, '-'), e);
	}
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
		if (e->ants == -1)
			e->ants = ft_atoi(line);
		type = find_type(line, type);
		split = ft_strsplit(line, ' ');
		if (type == -1 && is_room(split))
			room_push_front(&e->room, room_new(split[0], ft_atoi(split[1]), ft_atoi(split[2]), 0XFFFF00));
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
	ft_strdel(&line);
	return (NULL);
}

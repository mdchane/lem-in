/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 11:39:39 by mdchane           #+#    #+#             */
/*   Updated: 2019/04/24 12:38:55 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblem_in.h"

static char		*end_room(t_env *e, char ***splt, char *line)
{
	if (e->end)
	{
		grapht_push_back(&e->g, e->end);
	}
	free_tab(splt);
	return (line);
}

static void		start_room(t_env *e, char **splt, int *type)
{
	grapht_push_front(&e->g, g_new(splt[0], ft_atoi(splt[1]),
	ft_atoi(splt[2])));
	e->start = e->g;
	*type = -1;
}

static void		set_endroom(t_env *e, char **splt, int *type)
{
	e->end = g_new(splt[0], ft_atoi(splt[1]), ft_atoi(splt[2]));
	*type = -1;
}

static char		*parse_rooms(t_env *e, int type)
{
	char		*line;
	char		**splt;

	while (get_next_line(0, &line) > 0)
	{
		e->buff = ft_strjoinfree(e->buff, line);
		type = find_type(line, type);
		splt = ft_strsplit(line, ' ');
		if (type == -1 && is_room(splt))
			grapht_push_back(&e->g, g_new(splt[0],
			ft_atoi(splt[1]), ft_atoi(splt[2])));
		else if (type == START && is_room(splt))
			start_room(e, splt, &type);
		else if (type == END && is_room(splt))
			set_endroom(e, splt, &type);
		else if (is_neigh(line) && type == -1)
			return (end_room(e, &splt, line));
		else if (line[0] != '#')
			error("ERROR\n");
		free_tab(&splt);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return (NULL);
}

void			parsing(t_env *e)
{
	char	*line;
	int		type;

	type = -1;
	parse_nb_ants(e);
	line = parse_rooms(e, type);
	if (!e->start || !e->end || !line)
		error("ERROR\n");
	parse_neigh(e, line);
}
